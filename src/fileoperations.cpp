/*
 * FileOperations.cpp
 *
 *  Created on: May 7, 2024
 *      Author: leijon
 */
#include <string.h>
#include "../inc/fileoperations.h"



//	The constructor is in charge of opening both input- and output-files,
//	getting the filesize and position the file pointer at the beginning
//	of the input file.
//
//	It also gives an error if opening the files don't work out
//
fileoperations::fileoperations(std::string _inputFileName, std::string _outputFileName, bool _verbose)
{

	// assign filenames to object variables
	fo_inputFileName	= _inputFileName;
	fo_outputFileName	= _outputFileName;
	fo_verbose			= _verbose;

	// open input file, position the fp at the end
	fo_inputFileStream.open(fo_inputFileName, std::ios::ate);
	//	if file is not open, flag an error and exit
	if(!fo_inputFileStream.is_open()){
		std::cout << "fileoperations(): Error opening input file: " << fo_inputFileName << ". Exiting..." << std::endl;
		exit(-1);
	}
	else{
		// get filesize and store it in object variable
		std::cout << "fileoperations(): inputFile.tellg(): " << fo_inputFileStream.tellg() << std::endl;
		fo_inputFileSize = fo_inputFileStream.tellg();
		// After getting the filesize, set file pointer at beginning of file
		fo_inputFileStream.seekg(0, std::ios::beg);
	}


	// open the output file
	fo_outputFileStream.open(fo_outputFileName);
	//	if file is not open, flag an error and exit
	if(!fo_outputFileStream.is_open()){
		std::cout << "fileoperations(): Error opening output file: " << fo_outputFileName << ". Exiting..." << std::endl;
		exit(-1);
	}

	//	update current file pointer positions
	//fo_updateFilepointerPositions();
}




//	The destructor is in charge of closing the files upon exit
fileoperations::~fileoperations()
{
	// Close files upon exiting
	fo_inputFileStream.close();
	fo_outputFileStream.close();

}
