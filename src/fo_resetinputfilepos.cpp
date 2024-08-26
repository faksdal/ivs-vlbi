/*
 * resetinputfilepos.cpp
 *
 *  Created on: 14 May 2024
 *      Author: jole
 */

//
// TODO - describe what we're calculating here...
//

#include "fileoperations.h"



unsigned long fileoperations::fo_resetInputFilePos(void)
{
	fo_inputFileStream.clear();
	//std::cout << "fileoperations::resetInputFilePos(): cleared input file" << std::endl;
	if(fo_inputFileStream.bad()){
		std::cout << "fileoperations::resetInputFilePos(): stream is bad!" << std::endl;
		std::cout << "fileoperations::resetInputFilePos(): " << fo_inputFileStream.bad() << std::endl;
		exit(-1);

	}
	if(!fo_inputFileStream.good()){
		//std::cout << "fileoperations::resetInputFilePos(): stream is not good!" << std::endl;
		exit(-1);
	}
	if(!fo_inputFileStream.good()){
		//std::cout << "fileoperations::resetInputFilePos(): stream is not good!" << std::endl;
		exit(-1);
	}

	fo_inputFileStream.seekg(0, std::ios::beg);
	//cout << "fileoperations::resetInputFilePos(): seekg to beginning" << endl;

	if(fo_inputFileStream.fail()){
		std::cout << "fileoperations::resetInputFilePos(): stream failed!" << std::endl;
		std::cout << "fileoperations::resetInputFilePos(): " << fo_inputFileStream.fail() << std::endl;
		exit(-1);

	}

	//eof = false;
	return(fo_inputFileStream.tellg());
}
