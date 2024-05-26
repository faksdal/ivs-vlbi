/*
 * antennaRemovedFromSession.cpp
 *
 *  Created on: 26 May 2024
 *      Author: jole
 */
/*
	bit | 0 | 1 | 2 | 3 | 4  | 5  |  6  |  7  |
	    | 1 | 2 | 4 | 8 | 16 | 32 | 64  | 128 |

*/
#include "fileoperations.h"


// checking if the particuar antenna is removed from session, can be done by
// backing up the .html-file until we reach the "station-id" string, then we
// check to see if we find "station-id removed" from that position.
bool fileoperations::fo_antennaRemovedFromSession(string _antenna, size_t _startPos)
{
	bool	retVal = false;

	// assigning a new search term
	string	searchTerm = "station-id";

	// subtract at least the length of the new serch term, 'cause we're not
	// gonna find it any later than that...
	size_t	searchIndex = (_startPos - searchTerm.length());

	short c = 0;
	// Take one step backwards and do a search.
	// If we haven't found it in 90 step, we're not gonna...
	while((fo_inputBuffer.find(searchTerm, searchIndex)) > searchIndex){
		// Means were still looking for the search term...
		searchIndex--;

		// If we haven't found it 90 stes back, we're not gonna find it
		// Something's wrong and we should stop the search
		if(c++ >= 90){
			//cout << "fileoperations::antennaRemovedFromSession(): c++ >= 90" << endl;
			break;
		}
	}

	// If we're here, one of two things has happened:
	//		1: we found a match for "station-id"
	//		2: we searched past the normal range without finding the term "station-id"

	if(c >= 90)
		return(true);


	searchTerm = "station-id removed";
	size_t s = fo_inputBuffer.find(searchTerm, searchIndex);

	// If search result equals string::npos, no match was found
	if( s == string::npos){
		//cout << "find returned string::npos" << endl;
		retVal = false;
	}
	// If search returns a position greater than our start position,
	// it means we found it further down the string nd it don't
	// apply to the antenna in question
	else if(s > searchIndex){
		//cout << "find returned a hit, further down the string" << endl;
		retVal = false;
	}
	// If we however found it a out current position, it means this antenna
	// is removed from session
	else if(s == searchIndex){
			//cout << "find returned a hit, this antenna is removed from the session" << endl;
			retVal = true;
	}

	return(retVal);
}
