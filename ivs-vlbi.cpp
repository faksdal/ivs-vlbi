/*******************************************************************************
 *
 * ivs-vlbi.cpp; Created by Jon Leithe
 * Date: 3/5-2024
 *
 * 
*******************************************************************************/
  

#include <getopt.h>
#include <iostream>

//#include <stdio.h> 
//#include <string.h>
//#include <stdbool.h>

#include "fileexists.h"
#include "fileoperations.h"

using namespace std;



// Driver code
int main(int argc, char **argv)
{
	int		searchTermsIndex;

	string	inputFileName;
	string	outputFileName;

	string	searchTerms[MAXSEARCHTERMS];

	bool	inputFileNameSet;
	bool	outputFileNameSet;
	bool	searchTermsSet;
	bool	verbose;


	inputFileNameSet =  outputFileNameSet = searchTermsSet = verbose = false;

	//	getopt variables
	int		c, optionIndex;

	char	*shortOptions = (char*)"i:o:s:vh";
	struct option	longOptions[] = {
		{"search",		required_argument,	NULL,	's'},
		{"input-file",	required_argument,	NULL,	'i'},
		{"output-file",	required_argument,	NULL,	'o'},
		{"verbose",		no_argument,		NULL,	'v'},
		/*{"lat",		required_argument,	NULL,	4},
		{"lon",		required_argument,	NULL,	5},
		{"dst",		required_argument,	NULL,	6},
		{"verbose",	no_argument,		NULL,	'v'},*/
		{"help",		no_argument,		NULL,	'h'},
		{0, 0, 0, 0}
	};	//End of getopt()-variables

	// reset searchArrayIndex, use to keep track of how many search terms we have
	searchTermsIndex = 0;

	//	getopt() switch statement
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
		switch(c){
			case 's':	{
							if(searchTermsIndex >= MAXSEARCHTERMS){
								cout << "main(): MAXSEARCHTERMS reached!";
								break;
							}

							if(!searchTermsSet)
								searchTermsSet = true;

							searchTerms[searchTermsIndex] = optarg;
							searchTermsIndex++;
							break;
						}
			case 'i':	{
							// if file don't exists, give a message and exit
							if(!fileexists(optarg)){
								cout << "[ERROR] main(): Input file " << optarg << " does not exist!" << endl;
								cout << "[ERROR] main(): Exiting..." << endl;
								exit(-1);
							}

							inputFileName		= optarg;
							inputFileNameSet	= true;

							if(verbose)
								cout << "[OK]    main(): Input file name set to: " << inputFileName << endl;

							break;
						}
			case 'o':	{
							// if outputfile exists, present the user with a choice to overwrite
							if(fileexists(optarg)){
								cerr << "[ERROR] main(): " << optarg << " exists! Overwrite? y/n: ";
								char c;
								cin >> c;
								if(c == 'n' || c == 'N')
									exit(-1);
							}

							outputFileName		= optarg;
							outputFileNameSet	= true;

							if(verbose)
								cout << "[OK]    main(): Output file name set to: " << outputFileName << endl;

							break;
						}
			case 'h':	{
							cout << "main(): Provide some useful help to the user!" << endl;
							exit(1);
						}
			case 'v':	{
							verbose = true;
							cout << "[OK]    Verbose output!" << endl;
							break;
						}
			default:	{
							cout << "main: Switch default\n" << endl;
							break;
						}
		}	//end of getopt() switch statement
	}	// end of while-loop






	//	If all necessities are in place, we can continue to
	//	create an object-instance and initiate the search...
	fileoperations	*fo;

	if(inputFileNameSet && outputFileNameSet){

		if(verbose)
			cout << "[OK]    main(): We have valid filenames!" << endl;

		fo = new fileoperations(inputFileName, outputFileName, verbose);
		if(!fo){
			cerr << "[ERROR] main(): failed to create object: fo = new fileoperations(inputFileName, outputFileName, verbose);, exiting..." << endl;
			exit(-1);
		}


		// read content of input file to memory
		fo->fo_readFromInputFile();


		//fo->printInputBufferToScreen();

	} // if(inputFileNameSet && outputFileNameSet)

	if(searchTermsSet && inputFileNameSet && outputFileNameSet){
		if(searchTermsIndex == 1)
			cout << "main(): We have " << searchTermsIndex << " search term" << endl;
		else if(searchTermsIndex > 1)
			cout << "main(): We have " << searchTermsIndex << " search terms" << endl;

		// now we need to parse the fo_inputBuffer to create the output we want
		// we'll store the output in fo_outputBuffer
		fo->fo_parseInputBuffer("Ns");



	}

	delete fo;

    return(0);
}

