/*
 * FileOperations.cpp
 *
 *  Created on: May 7, 2024
 *      Author: leijon
 */
#include <string.h>
#include "fileoperations.h"



//	The constructor is in charge of opening both input- and output-files,
//	getting the filesize and position the file pointer at the beginning
//	of the input file. It also read the input-files content into memory.
//
//	It gives an error if opening the files don't work out.
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
		//std::cout << "fileoperations(): inputFile.tellg(): " << fo_inputFileStream.tellg() << std::endl;
		fo_inputFileSize = fo_inputFileStream.tellg();
		// After getting the filesize, set file pointer at beginning of file
		fo_inputFileStream.seekg(0, std::ios::beg);
	}


	// open the output file, if we're given a name for it
	if(fo_outputFileName.length() > 0){
		fo_outputFileStream.open(fo_outputFileName);
		//	if file is not open, flag an error and exit
		if(!fo_outputFileStream.is_open()){
			std::cout << "fileoperations(): Error opening output file: " << fo_outputFileName << ". Exiting..." << std::endl;
			exit(-1);
		}
	}

	//std::cout << "File pointer after reset :" << fo_resetInputFilePos() << std::endl;

	// read contents of input-file to memory
	// this funtion also closes the input-file
	fo_readFromInputFile();

	// print fo_inputBuffer to tty, for debug purposes...
	//std::cout << fo_inputBuffer << std::endl;
}




//	The destructor is in charge of closing the files upon exit
fileoperations::~fileoperations()
{
	// Close files upon exiting
	fo_inputFileStream.close();
	fo_outputFileStream.close();

}
