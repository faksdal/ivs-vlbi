/*
 * updateFilepointerPositions.cpp
 *
 *  Created on: May 8, 2024
 *      Author: leijon
 */

//
// TODO - describe what we're calculating here...
//

#include "../inc/fileoperations.h"



void fileoperations::updateFilepointerPositions(void)
{
	//
	//	update current file pointer positions
	//
	currentInputFilePos		= inputFile.tellg();
	currentOutputFilePos	= outputFile.tellp();

	//cout << "CurrentInputFilePos: " << currentInputFilePos << ", inputFileSize:" << inputFileSize << endl;
	if(currentInputFilePos >= inputFileSize){
		eof = true;
		//cout << "updateFilepointerPositions(): eof = true" << endl;
	}
	else{
		eof = false;
		//cout << "updateFilepointerPositions(): eof = false" << endl;
	}

	//cout << "updateFilepointerPositions(): File pointer input: " << getCurrentInputFilePos() << endl;
	//cout << "updateFilepointerPositions(): File pointer output: " << getCurrentOutputFilePos() << endl;
}
