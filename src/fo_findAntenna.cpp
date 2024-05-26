/*
 * findAntenna.cpp
 *
 *  Created on: 26 May 2024
 *      Author: jole
 */

//
// TODO - describe what we're calculating here...
//

#include "fileoperations.h"

size_t fileoperations::fo_findAntenna(string _antenna, size_t _startPos)
{
	size_t	retVal;
	//cout << "Searching for " << _antenna << ", starting at position " << _startPos << endl;
	retVal = fo_inputBuffer.find(_antenna, _startPos);

	//if(retVal == string::npos)
		//cout << "string::npos returned" << endl;

	return(retVal);
}


