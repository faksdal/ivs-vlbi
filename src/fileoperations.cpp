/*
 * FileOperations.cpp
 *
 *  Created on: May 7, 2024
 *      Author: leijon
 */

#include <string>

#include "fileexists.h"
#include "fileoperations.h"



//	The constructor is in charge of opening both input- and output-files,
//	getting the filesize and position the file pointer at the beginning
//	of the input file.
//
//	It also gives an error if opening the files don't work out

fileoperations::fileoperations(string _inputFileName, string _outputFileName)
{

	// assign filenames to object variables
	inputFileName	= _inputFileName;
	outputFileName	= _outputFileName;

	// opening input file, the existense of the file is already
	// checked by the caller
	inputFileStream.open(inputFileName, ios::ate);

	//inputFileStream;
	//outputFileStream;

	/*
	// open input file, position the fp at the end
	inputFile.open(inputFileName, ios::ate);
	//	if file is not open, flag an error and exit
	if(!inputFile.is_open()){
		cout << "fileoperations(): Error opening input file: " << inputFileName << ". Exiting..." << endl;
		exit(-1);
	}
	else{
		// get filesize and store it in object variable
		cout << "fileoperations(): inputFile.tellg(): " << inputFile.tellg() << endl;
		inputFileSize = inputFile.tellg();
		// After getting the filesize, set file pointer at beginning of file
		inputFile.seekg(0, ios::beg);
	}
	*/


	/*
	// open the output file
	outputFile.open(outputFileName);
	//	if file is not open, flag an error and exit
	if(!outputFile.is_open()){
		cout << "fileoperations(): Error opening output file: " << outputFileName << ". Exiting..." << endl;
		exit(-1);
	}
	*/




}



//	The destructor is in charge of closing the files upon exit
fileoperations::~fileoperations()
{
	// Close files upon exiting
	//inputFile.close();
	//outputFile.close();

}
