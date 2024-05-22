/*
 * parseInputBuffer.cpp
 *
 *  Created on: May 22, 2024
 *      Author: leijon
 */

//
// TODO - describe what we're calculating here...
//

//#include <string.h>

#include "fileoperations.h"


void fileoperations::parseInputBuffer(void)
{
	unsigned int	stringLength;

	string			searchTerm;


	// start by clearing the fo_outputBuffer
	fo_outputBuffer.clear();

	//cout << "fileoperations::parseInputBuffer(): " << endl;

	searchTerm = "<title>";
	fo_inputBufferIndex = fo_inputBuffer.find(searchTerm);
	if(fo_inputBufferIndex != string::npos){
		//cout << "fileoperations::parseInputBuffer(): fo_inputBufferIndex: " << fo_inputBufferIndex << endl;
		fo_inputBufferIndex += searchTerm.length();
		//cout << "fileoperations::parseInputBuffer(): searchTerm.length(): " << searchTerm.length() << endl;
		//cout << "fileoperations::parseInputBuffer(): fo_inputBufferIndex: " << fo_inputBufferIndex << endl;
		searchTerm = "</title>";
		stringLength = (fo_inputBuffer.find(searchTerm)) - fo_inputBufferIndex;

		// string substr (size_t pos = 0, size_t len = npos) const;
		fo_outputBuffer.append(fo_inputBuffer.substr(fo_inputBufferIndex, stringLength));
		for(unsigned int i = 0; i < stringLength; i++){
			if(fo_outputBuffer[i] == '\n')
				fo_outputBuffer[i] = ' ';
		}

	}

	fo_inputBufferIndex = 0;
	searchTerm = "<h1 class=\"title\">";
	fo_inputBufferIndex = fo_inputBuffer.find(searchTerm);
	if(fo_inputBufferIndex != string::npos){
		cout << "fileoperations::parseInputBuffer(): fo_inputBufferIndex: " << fo_inputBufferIndex << endl;
		fo_inputBufferIndex += searchTerm.length();
		//cout << "fileoperations::parseInputBuffer(): searchTerm.length(): " << searchTerm.length() << endl;
		//cout << "fileoperations::parseInputBuffer(): fo_inputBufferIndex: " << fo_inputBufferIndex << endl;
		searchTerm = "</h1>";
		stringLength = (fo_inputBuffer.find(searchTerm)) - fo_inputBufferIndex;

		// string substr (size_t pos = 0, size_t len = npos) const;
		fo_outputBuffer.append(fo_inputBuffer.substr(fo_inputBufferIndex, stringLength));


	}

	cout << "fileoperations::parseInputBuffer(): fo_outputBuffer: " << endl;
	cout << fo_outputBuffer << endl;

}
