/*
 * ivsSessions.cpp
 *
 *  Created on: Aug 29, 2024
 *      Author: leijon
 */


#include "ivsSessions.h"



ivsSessions::ivsSessions(std::string _inputFileName, std::string _outputFileName, bool _verbose)
            : fileoperations(_inputFileName, _outputFileName, _verbose)
{
	std::cout << "We're inside ivsSessions!" << std::endl;

	sl = new sessionList;

}



ivsSessions::~ivsSessions()
{
	// TODO Auto-generated destructor stub
}

