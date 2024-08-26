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


void fileoperations::fo_parseInputBuffer(string _antennaName)
{
	bool		quit = false;

	size_t		antennaIndex, searchIndex;

	string		antennaName;
	string		htmlToken;
	string		sessionTypeString = "session-type";



	antennaName = _antennaName;

	// start by clearing the fo_outputBuffer
	fo_outputBuffer.clear();

	// Start at the beginning
	antennaIndex = 0;

	//cout << "fo_inputBuffer.length(): " << fo_inputBuffer.length() << endl;

	while(!quit){
		// First we search for the antenna name, returning an index for that position
		searchIndex = fo_findAntenna(antennaName, antennaIndex);

		cout << "            searchIndex: " << searchIndex << endl;
		cout << "fo_inputBuffer.length(): " << fo_inputBuffer.length() << endl;

		// If no match
		if(searchIndex == string::npos){
			cout << "No match for " << antennaName << " starting at position " << antennaIndex << endl;
			quit = true;
		}
		// if match
		else if(searchIndex < fo_inputBuffer.length()){
			antennaIndex = searchIndex;
			cout << "We have a match for " << antennaName << " at " << antennaIndex << endl;
		}
		else if(searchIndex >= fo_inputBuffer.length()){
			cout << "We have exceeded the buffer" << endl;
			quit = true;
		}

		antennaIndex += antennaName.length();
		cout << "antennaIndex: " << antennaIndex << endl;

	} // while(antennaIndex <= fo_inputBuffer.length())

}
