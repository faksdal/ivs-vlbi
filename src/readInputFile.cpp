/*
 * readInputFile.cpp
 *
 *  Created on: May 21, 2024
 *      Author: leijon
 */

//
// TODO - describe what we're calculating here...
//


#include "fileoperations.h"



streampos fileoperations::fo_readLineFromInputFile(streampos _newFilePosition, string &_readBuffer)
{
	streampos	retVal;

	fo_inputFileStream.seekg(_newFilePosition, istream::beg);
	retVal = fo_inputFileStream.tellg();

	cout << "streampos _newFilePosition = " << _newFilePosition << ", retVal = " << retVal << endl;

	_readBuffer = "Hello Jon!";

	return(retVal);
}
