/*******************************************************************************
 *
 * ivs-vlbi.cpp; Created by Jon Leithe
 * Date: 21/8-2024
 *
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
//#include "ivsSessions.h"

//using namespace std;



// Driver code
int main(int argc, char **argv)
{
	int		searchTermsIndex;

	std::string	inputFileName;
	std::string	outputFileName;

	std::string	searchTerms[MAXSEARCHTERMS];

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
								std::cout << "main(): MAXSEARCHTERMS reached";
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
								std::cout << "[ERROR] main(): Input file " << optarg << " does not exist!" << std::endl;
								std::cout << "[ERROR] main(): Exiting..." << std::endl;
								exit(-1);
							}

							inputFileName		= optarg;
							inputFileNameSet	= true;

							if(verbose)
								std::cout << "[OK]    main(): Input file name set to: " << inputFileName << std::endl;

							break;
						}
			case 'o':	{
							// if outputfile exists, present the user with a choice to overwrite
							if(fileexists(optarg)){
								std::cerr << "[WARNING] main(): " << optarg << " exists! Overwrite? y/n: ";
								char c;
								std::cin >> c;
								if(c == 'n' || c == 'N')
									exit(-1);
							}

							outputFileName		= optarg;
							outputFileNameSet	= true;

							if(verbose)
								std::cout << "[OK]    main(): Output file name set to: " << outputFileName << std::endl;

							break;
						}
			case 'h':	{
							std::cout << "main(): Provide some useful help to the user!" << std::endl;
							exit(1);
						}
			case 'v':	{
							verbose = true;
							std::cout << "[OK]    Verbose output!" << std::endl;
							break;
						}
			default:	{
							std::cout << "main: Switch default\n" << std::endl;
							break;
						}
		}	//end of getopt() switch statement
	}	// end of while-loop





	/*************************************************************************/

	//	If all necessities are in place, we can continue to
	//	create an object-instance and initiate the search...
	fileoperations	*fo;

	if(inputFileNameSet && outputFileNameSet){

		if(verbose)
			std::cout << "[OK]    main(): We have valid filenames!" << std::endl;

		fo = new fileoperations(inputFileName, outputFileName, verbose);
		if(!fo){
			std::cerr << "[ERROR] main(): failed to create object: fo = new fileoperations(inputFileName, outputFileName, verbose);, exiting..." << std::endl;
			exit(-1);
		}

		// read content of input file to memory
		//fo->fo_readFromInputFile();

		//fo->printInputBufferToScreen();

	} // if(inputFileNameSet && outputFileNameSet)

	if(searchTermsSet && inputFileNameSet && outputFileNameSet){
		if(searchTermsIndex == 1)
			std::cout << "main(): We have " << searchTermsIndex << " search term" << std::endl;
		else if(searchTermsIndex > 1)
			std::cout << "main(): We have " << searchTermsIndex << " search terms" << std::endl;

		// now we need to parse the fo_inputBuffer to create the output we want
		// we'll store the output in fo_outputBuffer
		//fo->fo_parseInputBuffer("Ns");
		//fo->fo_parseInputBuffer("Nn");

	} // if(searchTermsSet && inputFileNameSet && outputFileNameSet)



	delete fo;

	/*************************************************************************/

	/*
	if(searchTermsSet && inputFileNameSet && outputFileNameSet){
		ivsSessions*	sessions;

		sessions = new ivsSessions(inputFileName, outputFileName);
	}
	*/

    return(0);
}

