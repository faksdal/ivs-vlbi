/*
 * resetinputfilepos.cpp
 *
 *  Created on: 14 May 2024
 *      Author: jole
 */

//
// TODO - describe what we're calculating here...
//

#include "../inc/fileoperations.h"



unsigned long fileoperations::resetInputFilePos(void)
{
	inputFile.clear();
	cout << "fileoperations::resetInputFilePos(): cleared input file" << endl;
	if(inputFile.bad()){
		cout << "fileoperations::resetInputFilePos(): stream is bad!" << endl;
		cout << "fileoperations::resetInputFilePos(): " << inputFile.bad() << endl;
		exit(-1);

	}
	if(!inputFile.good()){
		cout << "fileoperations::resetInputFilePos(): stream is not good!" << endl;
		exit(-1);
	}
	if(!inputFile.good()){
			cout << "fileoperations::resetInputFilePos(): stream is not good!" << endl;
			exit(-1);
		}
	inputFile.seekg(0, ios::beg);
	//cout << "fileoperations::resetInputFilePos(): seekg to beginning" << endl;
	if(inputFile.fail()){
		cout << "fileoperations::resetInputFilePos(): stream failed!" << endl;
		cout << "fileoperations::resetInputFilePos(): " << inputFile.fail() << endl;
		exit(-1);

	}

	eof = false;
	return(inputFile.tellg());
}
