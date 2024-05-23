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
	int				i;

	unsigned int	sessionTypeIndex, antennaIndex, htmlIndex;

	string			searchTerm = "Ns";
	string			htmlToken;
	string			sessionTypeString = "session-type";



	/*
	 * Start off by finding the string class="session-type", take note of its index
	 * From that index, search for the searchterm (e.g. the antenna Ns or Nn), if found; take note of that index
	 * Go back to the session-type-index, extract useful data about the session and put it into a string
	 * repeat the process
	*/

	// start by clearing the fo_outputBuffer
	fo_outputBuffer.clear();

	sessionTypeIndex = fo_inputBuffer.find(sessionTypeString);

	antennaIndex = fo_inputBuffer.find(searchTerm, sessionTypeIndex);

	htmlToken = "</a>";
	htmlIndex = fo_inputBuffer.find(htmlToken, sessionTypeIndex);
	cout << "htmlIndex: " << htmlIndex << endl;

	i = 0;
	while(fo_inputBuffer[htmlIndex - i] != '>'){
		//cout << fo_inputBuffer[htmlIndex - i];
		i++;
	}
	i--;

	// string& append (const string& str, size_t subpos, size_t sublen);
	fo_outputBuffer.append(fo_inputBuffer, htmlIndex - i, i);
	fo_outputBuffer.append("\tJon\tLeithe\t9173\tNy-Ålesund");

	cout << "fo_outputBuffer:";
	cout << fo_outputBuffer << endl;

}
