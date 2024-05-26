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
	//size_t			i;

	unsigned int	/*sessionTypeIndex,*/ antennaIndex, searchIndex;

	string			searchTerm = "Ns";
	string			htmlToken;
	string			sessionTypeString = "session-type";



	/*
	 * Start off by finding the string class="session-type", take note of its index
	 * From that index, search for the searchterm (e.g. the antenna Ns or Nn), if found; take note of that index
	 * Go back to the session-type-index, extract useful data about the session and put it into a string
	 * repeat the process
	*/

	/*
	 *	The position of the first character of the first match.
	 *	If no matches were found, the function returns string::npos.
	*/

	// start by clearing the fo_outputBuffer
	fo_outputBuffer.clear();

	// First we search for the antenna name, returning an index for that position
	antennaIndex = fo_inputBuffer.find(searchTerm);
	cout << "parseInputBuffer(): antennaIndex: " << antennaIndex << endl;

	// Then we need to back up making sure the particular antenna is not removed from the session
	// This can be done by reversing a bit, and do a search for the phrase "station-id removed"
	// Let's keep the antennaIndex where it's at, and assign teh value of antennaInde to searchIndex,
	// using searchIndex to back up the string and search for the new search term
	searchIndex = antennaIndex;
	searchTerm = "<li class=\"station-id ";
	searchIndex -= searchTerm.length();

	//i = string::npos;
	while( (fo_inputBuffer.find(searchTerm, searchIndex)) == string::npos){
		// Means were still looking for the search term...
		searchIndex--;
		cout << "searchIndex: " << searchIndex << endl;
	}
	cout << "Search term " << searchTerm << "found at " << searchIndex << endl;

	/*
	i = fo_inputBuffer.find(searchTerm);
	if(i != std::string::npos){
		// means we found it
		cout << "Search term found" << endl;
	}
	*/



	//antennaIndex = fo_inputBuffer.find(searchTerm, sessionTypeIndex);

	//htmlToken = "</a>";
	//htmlIndex = fo_inputBuffer.find(htmlToken, sessionTypeIndex);
	//cout << "htmlIndex: " << htmlIndex << endl;

	/*
	i = 0;
	while(fo_inputBuffer[htmlIndex - i] != '>'){
		i++;
	}
	i--;
	*/

	// string& append (const string& str, size_t subpos, size_t sublen);
	//fo_outputBuffer.append(fo_inputBuffer, htmlIndex - i, i);


	cout << "fo_outputBuffer:";
	cout << fo_outputBuffer << endl;

}
