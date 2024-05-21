/******************************************************************************
 *
 * vlbi-automation.cpp; Created by Jon Leithe based on https://www.geeksforgeeks.org/html-parser-in-c-cpp/
 * Date: 3/5-2024
 *
 * 
******************************************************************************/
  

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
	//int		searchTermsArrayIndex;

	string	inputFileName;
	string	outputFileName;

	string	searchTermsArray[MAXSEARCHTERMS];

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

	//	reset searchArrayIndex, use to keep track of serach terms
	//searchTermsArrayIndex = 0;

	//	getopt() switch statement
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
		switch(c){
			case 's':	{
							//cout << "main: searchTermsArrayIndex: " << searchTermsArrayIndex << endl;
							/*
							if(searchTermsArrayIndex >= MAXSEARCHTERMS){
								cout << "main(): MAXSEARCHTERMS reached!";
								break;
							}
							*/

							if(!searchTermsSet)
								searchTermsSet = true;

							//searchTermsArray[searchTermsArrayIndex] = optarg;
							//cout << "main: ...search string added: " << searchTermsArray[searchTermsArrayIndex++] << endl;
							//searchTermsArrayIndex++;
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
	fileoperations *fo;
	if(inputFileNameSet && outputFileNameSet){

		if(verbose)
			cout << "[OK]    main(): We have valid filenames!" << endl;

		fo = new fileoperations(inputFileName, outputFileName, verbose);
		if(!fo){
			cerr << "[ERROR] main(): failed to create object: fo = new fileoperations(inputFileName, outputFileName, verbose);, exiting..." << endl;
			exit(-1);
		}

		//fo->streampos	fo_readInputFile(streampos _newFilePosition, string &_readBuffer);
		streampos	newFilePosition = 299;
		string		readBuffer;

		cout << "main(): current input file position: " << fo->fo_getCurrentInputFilePos() << endl;
		fo->fo_readLineFromInputFile(newFilePosition, readBuffer);
		cout << "main(): " << readBuffer << endl;

	} // if(inputFileNameSet && outputFileNameSet)

	/*  && searchTermsSet)
		fileoperations fo(inputFileName, outputFileName, searchTermsArray);

		unsigned long	startPosition = 0L;
		for(short i = 0; i < searchTermsArrayIndex; i++){
			cout << "main(): First search term index: " << i << endl;
			cout << "main(): Search string:  " << searchTermsArray[i] << endl;



			while(!fo.eof){

				//cout << "main(): Inside while(!fo.eof)-loop. " << endl;
				//cout << "main(): searchTermsArrayIndex:  " << i << endl;
				cout << "main(): Starting new search for:  " << searchTermsArray[i] << endl;
				//		cin >> s;

				startPosition = (fo.find(startPosition, searchTermsArray[i])) + searchTermsArray[i].length();
				cout << "main(): Position: " << startPosition << endl;

				//cout << "main(): startPosition: " << startPosition << endl;
				//fo.eof = true;

			}
			// Reset startPosition after we are done with a search term
			cout << "main(): Input file pointer pos: " << fo.resetInputFilePos() << endl;
			cout << "main(): One search term done, move on to the next..." << endl;
			//cin >> s;

			startPosition = 0L;
		}

		cout << "main(): Number of search hits: " << fo.getNumberOfSearchHits() << endl;
		for(int j = 0; j <= fo.getNumberOfSearchHits(); j++){
			cout << "main(): Search hit # " << j+1 << ": " << fo.hits[j].searchTerm << ", at position: " << fo.hits[j].position << endl;
		}
	}

	else{
		cout << "Missing parameters... Quitting!" << endl;
		// TODO: provide some useful information
	}
	*/

	delete fo;

    return(0);
}

