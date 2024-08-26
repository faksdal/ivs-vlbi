/*
 * skipInitialWhitespace.cpp
 *
 *  Created on: 7 May 2024
 *      Author: jole
 */


#include "../inc/fileoperations.h"



string fileoperations::skipInitialWhitespace(string _stringToSkip)
{
	//
	//	Get rid of any initial whitepace, and pass the
	//	string to the html parser routine
	//
	char* ptr = (char*)_stringToSkip.c_str();

	//cout << "ptr before removing whitespace: " << ptr;
	while(*ptr++ == ' ');
	*ptr--;

	string retVal = ptr;
	return(retVal);
}
