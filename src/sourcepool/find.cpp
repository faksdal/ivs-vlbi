/*
 *	find.cpp
 *
 *  Created on: May 7, 2024
 *      Author: leijon
 *
 */

//
// TODO - add functionality to sum up all occurences of a search term, with fp to where they are in the file
//

#include <string>
//include <sstream>

#include "../inc/fileoperations.h"



//	find() searches for _searchString, starting at _startPosition, returning
//	the position in the file where the string starts.
//	find() also updates the file pointer positions
unsigned long fileoperations::find(unsigned long _startPosition, std::string _searchString)
{
	std::string			inputString, searchString;

	unsigned long	filePosition	= 0L;		// This starts with a 0
	unsigned long	position		= 0L;
	unsigned long	stringPosition	= 0L;		// This starts with a 0
	//unsigned long	counter;


	std::cout << "fileoperations::find() - 33" << std::endl;

	// If inputfile is not open, we exit with an error
	if(!fo_inputFileStream.is_open()){
		std::cout << "fileoperations::find(): Error: inputfile not open, exiting with exit(-1)!" << std::endl;
		exit(-1);
	}

	//std::cout << "fileoperations::find() - 41" << std::endl;

	/*
	if(std::eof)
		std::cout << "eof = true" << std::endl;
	else
		std::cout << "eof = false" << std::endl;
	*/

	// search to _startPosition from the beginning of the file
	if(std::eof){
		std::cout << "Resetting input file pointer!" << std::endl;
		//fo_resetInputFilePos();
	}
	fo_inputFileStream.seekg(_startPosition, std::ios::beg);

	/*
	std::cout << "fileoperations::find() - 45" << std::endl;
	std::cout << "fileoperations::find(): input file position: " << inputFile.tellg() << std::endl;
	std::cout << "fileoperations::find() - 48" << std::endl;
	*/

	searchString = _searchString;

	//std::cout << "fileoperations::find() - 50" << std::endl;

	// As long as we have input from the file, we keep reading line by line
	hitsCounter = 0;
	while(getline(inputFile, inputString)){

		//std::cout << "fileoperations::find() - 56" << std::endl;

		filePosition = fo_inputFileStream.tellg();
		position = filePosition - inputString.length() - 1;

		//std::cout << "fileoperations::find() - 61" << std::endl;

		// Updates file pointer positions,and the eof flag,
		// the eof flag is used by the caller
		updateFilepointerPositions();

		//std::cout << "fileoperations::find() - 67" << std::endl;

		// Compare searchString with what we've just read from file.
		// If there's a match, we break out of the while-loop,
		// and return to caller with the position in the file where the string starts.
		if((stringPosition = inputString.find(searchString)) != std::string::npos){
			std::cout << "fileoperations::find(): Search match found: " << searchString << ", at position: " << position << std::endl;

			hits[hitsCounter].searchTerm	= searchString;
			hits[hitsCounter].position		= position;
			std::cout << "find(): Added " << searchString << " to hits[" << hitsCounter << "].searchTerm" << std::endl;

			hitsCounter++;
			numberOfSearchHits = hitsCounter;



			std::cout << "find(): Number of search hits : " << numberOfSearchHits << std::endl;
			std::cout << "find(): counter : " << hitsCounter << std::endl;

			//std::cout << "fileoperations::find() - 87" << std::endl;

			break;
		}


	} // while(getline(inputFile, inputString))


	//std::cout << "fileoperations::find() - 96" << std::endl;

	// Return current input file pointer position to the caller
	return(position);
}
