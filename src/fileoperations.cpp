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
fileoperations::fileoperations(string _inputFileName, string _outputFileName, bool _verbose)
{
	// assign verbose a value from the caller
	fo_verbose = _verbose;

	if(_verbose)
		cout << "[OK]    fileoperations::fileoperations(): Inside constructor." << endl;

	// assign filenames to object variables
	fo_inputFileName	= _inputFileName;
	fo_outputFileName	= _outputFileName;

	// opening input file, the existense of the file is already
	// checked by the caller
	// the opening flag ios::ate positions the filepointer at the end of the file
	fo_inputFileStream.open(fo_inputFileName, ios::ate);

	// check that the file is properly open and that we have
	// a valid filestream
	/*
		iostate value
		(member constant)	indicates	functions to check state flags
		good()	eof()	fail()	bad()	rdstate()

		-------------------------------------------------------------------------------------------------|
		| goodbit	| No errors (zero value iostate)			| true	| false	| false	| false	| goodbit|
		-------------------------------------------------------------------------------------------------|
		| eofbit	| End-of-File reached on input operation	| false	| true	| false	| false	| eofbit |
		-------------------------------------------------------------------------------------------------|
		| failbit	| Logical error on i/o operation			| false	| false	| true	| false	| failbit|
		-------------------------------------------------------------------------------------------------|
		| badbit	| Read/writing error on i/o operation		| false	| false	| true	| true	| badbit |
		-------------------------------------------------------------------------------------------------|
	*/
	if((fo_inputFileStream.rdstate() & ifstream::failbit ) != 0){
		cerr << "[ERROR] fileoperations::fileoperations(): Error opening input file: " << fo_inputFileName << ", exiting..." << endl;
		exit(-1);
	}
	else{
		if(fo_verbose)
			cout << "[OK]    fileoperations::fileoperations(): Input file: " << fo_inputFileName << ", open for reading." << endl;
	}

	// if we've gotten here, it's safe to assume we have a valid filestream.
	// Let's read the filesize and reset the filepointer to the beginning of the file.
	fo_inputFileSize = fo_inputFileStream.tellg();
	if(fo_verbose)
		cout << "[OK]    fileoperations::fileoperations(): input file size from ifstream.tellg(): " << fo_inputFileSize << " bytes" << endl;

	// After getting the filesize, set file pointer at beginning of file
	fo_inputFileStream.seekg(0, ios::beg);
	if(fo_inputFileStream.tellg() != 0){
		cerr << "[ERROR] fileoperations::fileoperations(): Search to start of file failed!" << endl;
		exit(-1);
	}
	else{
		if(fo_verbose)
			cout << "[OK]    fileoperations::fileoperations(): Search to start of file ok" << endl;
	}

	// open the output file
	fo_outputFileStream.open(fo_outputFileName);
	//	if file is not open, flag an error and exit
	if(!fo_outputFileStream.is_open()){
		cerr << "[ERROR] fileoperations::fileoperations(): Error opening output file: " << fo_outputFileName << ", exiting..." << endl;
		exit(-1);
	}

	// check that the file is properly open and that we have
	// a valid filestream
	if((fo_outputFileStream.rdstate() & ifstream::failbit ) != 0){
			cerr << "[ERROR] fileoperations::fileoperations(): Error opening output file: " << fo_outputFileName << ", exiting..." << endl;
			exit(-1);
	}
	else{
		if(fo_verbose)
			cout << "[OK]    fileoperations::fileoperations(): Output file: " << fo_outputFileName << ", open for writing." << endl;
	}

	//fo_inputFP	= 0;//fo_inputFileStream.tellg();
	//fo_outputFP	= 0;//fo_outputFileStream.tellp();
	fo_inputFilePosition	= fo_inputFileStream.tellg();
	fo_outputFilePosition	= fo_outputFileStream.tellp();

	if(fo_verbose){
		cout << "[OK]    fileoperations::fileoperations(): current value of input file pointer: " << fo_inputFilePosition << endl;
		cout << "[OK]    fileoperations::fileoperations(): current value of output file pointer: " << fo_outputFilePosition << endl;
	}

}



//	The destructor is in charge of closing the files upon exit
fileoperations::~fileoperations()
{
	if(fo_verbose)
		cout << "[OK]    fileoperations::~fileoperations(): closing files before exiting. " << endl;

	// Close filestreams upon exiting...
	if(fo_inputFileStream.is_open())
		fo_inputFileStream.close();

	if(fo_outputFileStream.is_open())
		fo_outputFileStream.close();

}
