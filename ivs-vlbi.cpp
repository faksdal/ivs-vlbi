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
	//string	searchTermsArray[MAXSEARCHTERMS];

	bool	inputFileNameSet, outputFileNameSet, searchTermsSet;


	inputFileNameSet =  outputFileNameSet = searchTermsSet = false;

	//	getopt variables
	int		c, optionIndex;

	char	*shortOptions = (char*)"I:i:o:h";
	struct option	longOptions[] = {
		{"include",		required_argument,	NULL,	'I'},
		{"input-file",	required_argument,	NULL,	'i'},
		{"output-file",	required_argument,	NULL,	'o'},
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
			case 'I':	{
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
								cout << "main(): Input file " << optarg << " does not exist!" << endl;
								cout << "main(): Exiting..." << endl;
								exit(-1);
							}

							inputFileName = optarg;
							inputFileNameSet = true;
							cout << "main(): Input file name set to: " << inputFileName << endl;

							break;
						}
			case 'o':	{
							// if outputfile exists, present the user with a choice
							if(fileexists(optarg)){
								cout << "main(): " << optarg << " exists! Overwrite? y/n: ";
								char c;
								cin >> c;
								if(c == 'n')
									exit(-1);
							}

							outputFileName = optarg;
							outputFileNameSet = true;
							cout << "main(): Output file name set to: " << outputFileName << endl;
							break;
						}
			case 'h':	{
							cout << "main(): Provide some useful help to the user!" << endl;
							exit(1);
						}
			default:	{
							cout << "main: Switch default\n" << endl;
							break;
						}
		}	//end of getopt() switch statement
	}	// end of while-loop





	/*
	//	If all necessities are in place, we can continue to
	//	create an object-instance and initiate the search...
	if(inputFileNameSet && outputFileNameSet && searchTermsSet){

		cout << "main(): Number of included search terms: " << searchTermsArrayIndex << endl;

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



    return(0);
}

