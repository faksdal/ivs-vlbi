/*
 * ivsSessions.cpp
 *
 *  Created on: Aug 29, 2024
 *      Author: leijon
 */


#include <vector>
#include <iostream>
#include "ivsSessions.h"



ivsSessions::ivsSessions(const char* _ptr, unsigned long _size)
{
	int				listCounter	= 0;
	unsigned long	c			= 0;
	std::string		buffer;

	// create the ivsList using the vector class
	// this makes it easier to manage dynamic lists
	std::vector<std::string>	ivsList;

	// read in the contents from *_ptr
	// one item per line (search for the linefeeds)
	// delete unnecessary stuff, like heading and footer
	// present the list to the user, with filter options

	std::cout << "Size of *_ptr: " << _size << std::endl;

	while(c < _size){
		buffer.append(1, *_ptr);
		if(*_ptr == '\r'){
			//buffer.append(1, *_ptr);
			//std::cout << "New line encountered" << std::endl;
			//std::cout << buffer << " added to the list" << std::endl;
			ivsList.push_back(buffer);
			//std::cout << ivsList[listCounter];
			listCounter++;
			buffer.clear();
			//*_ptr++;
		} // if(*_ptr == '\r')
		//buffer.append(1, *_ptr);
		*_ptr++;
		c++;
	} // while(c <= _size)


	// print the entire list
	std::cout << "Number of elements in the ivsList: " << ivsList.size() << std::endl;
	for(int i = 0; i < (int)ivsList.size(); i++){
		std::cout << ivsList[i] << std::endl;
	}

	/*

	ivsList.erase(ivsList.begin() + 1);

	std::cout << "Number of elements in the ivsList: " << ivsList.size() << std::endl;
	for(int i = 0; i < (int)ivsList.size(); i++){
		std::cout << ivsList[i] << std::endl;
	}
	*/

}



ivsSessions::~ivsSessions()
{
	// TODO Auto-generated destructor stub
}

