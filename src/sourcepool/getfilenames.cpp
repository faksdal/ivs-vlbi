/*
 * getfilenames.cpp
 *
 *  Created on: May 8, 2024
 *      Author: leijon
 */

//
// TODO - describe what we're calculating here...
//

#include "../inc/fileoperations.h"



string fileoperations::getOutputFileName(bool _printToScreen)
{
	if(_printToScreen)
		cout << "Outputfilename: " << outputFileName << endl;

	return(outputFileName);
}



string fileoperations::getInputFileName(bool _printToScreen)
{
	if(_printToScreen)
		cout << " Inputfilename: " << inputFileName << endl;
	return(inputFileName);
}
