/*
 * fo_readFromInputFile.cpp
 *
 *  Created on: May 22, 2024
 *      Author: leijon
 */

//
// TODO - describe what we're calculating here...
//

#include "fileoperations.h"
//#include "sessionlist.h"



// reads the compelete input file to memory
// contents stored in 'string fo_inputBuffer'
void fileoperations::fo_readFromInputFile(void)
{
	char	c;

	//cout << "fo_inputFileStream.rdstate(): " << fo_inputFileStream.rdstate() << endl;

	//cout << "goodbit: " << (fo_inputFileStream.good() ? "set" : "not set") << endl;
	//cout << "badbit: " << (fo_inputFileStream.bad() ? "set" : "not set") << endl;
	//cout << "eofbit: " << (fo_inputFileStream.eof() ? "set" : "not set") << endl;
	//cout << "failbit: " << (fo_inputFileStream.fail() ? "set" : "not set") << endl;

	// seek to start of input file
	fo_inputFileStream.seekg(0, std::ios::beg);
	if(fo_inputFileStream.tellg() != 0){
		std::cerr << "[ERROR] fileoperations::fo_readFromInputFile(): Search to start of file failed!" << std::endl;
		exit(-1);
	}
	else{
		if(fo_verbose)
			std::cout << "[OK]    fileoperations::fo_readFromInputFile(): Search to start of file ok" << std::endl;
	}

	//cout << "fileoperations::fo_readFromInputFile(): input file pointer position before read operation: " << fo_inputFileStream.tellg() << endl;

	// read the whole file to memory
	while(fo_inputFileStream.get(c).good()){
		fo_inputBuffer.append(1, c);
	}

	//cout << "fileoperations::fo_readFromInputFile(): input file pointer position after read operation: " << fo_inputFileStream.tellg() << endl;
	//cout << "goodbit: " << (fo_inputFileStream.good() ? "set" : "not set") << endl;
	//cout << "badbit: " << (fo_inputFileStream.bad() ? "set" : "not set") << endl;
	//cout << "eofbit: " << (fo_inputFileStream.eof() ? "set" : "not set") << endl;
	//cout << "failbit: " << (fo_inputFileStream.fail() ? "set" : "not set") << endl;

	// reset file pointer to beginning of file after read operation
	// and clear any failbit
	fo_inputFileStream.clear();
	fo_inputFileStream.seekg(0, std::ios::beg);
	if(fo_inputFileStream.tellg() != 0){
		std::cerr << "[ERROR] fileoperations::fo_readFromInputFile(): Search to start of file failed!" << std::endl;
		exit(-1);
	}

	// close the file as we are done reading!
	if(fo_inputFileStream.is_open())
		fo_inputFileStream.close();

	//cout << "fileoperations::fo_readFromInputFile(): input file pointer position after reset after read: " << fo_inputFileStream.tellg() << endl;

	//cout << "goodbit: " << (fo_inputFileStream.good() ? "set" : "not set") << endl;
	//cout << "badbit: " << (fo_inputFileStream.bad() ? "set" : "not set") << endl;
	//cout << "eofbit: " << (fo_inputFileStream.eof() ? "set" : "not set") << endl;
	//cout << "failbit: " << (fo_inputFileStream.fail() ? "set" : "not set") << endl;

	//cout << "fo_inputFileStream.rdstate(): " << fo_inputFileStream.rdstate() << endl;


	/*
	cout << "fileoperations::fo_readFromInputFile(): input file pointer position: " << fo_inputFileStream.tellg() << endl;
	fo_inputFileStream.clear(fo_inputFileStream.goodbit);
	fo_inputFileStream.clear(fo_inputFileStream.badbit);
	fo_inputFileStream.clear(fo_inputFileStream.eofbit);
	fo_inputFileStream.clear(fo_inputFileStream.failbit);

	fo_inputFileStream.seekg(0, ios::beg);
	cout << "fileoperations::fo_readFromInputFile(): input file pointer position: " << fo_inputFileStream.tellg() << endl;
	*/


	//cout << "goodbit: " << (fo_inputFileStream.good() ? "set" : "not set") << endl;
	//cout << "badbit: " << (fo_inputFileStream.bad() ? "set" : "not set") << endl;
	//cout << "eofbit: " << (fo_inputFileStream.eof() ? "set" : "not set") << endl;
	//cout << "failbit: " << (fo_inputFileStream.fail() ? "set" : "not set") << endl;

	//cout << "fo_inputFileStream.rdstate(): " << fo_inputFileStream.rdstate() << endl;
	/*
	cout << "Read from file:" << endl;
	cout << inputBuffer << endl;
	cout << "size of input buffer: " << inputBuffer.size() << endl;
	*/

	return;

}
