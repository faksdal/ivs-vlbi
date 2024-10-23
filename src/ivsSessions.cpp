/*
 * ivsSessions.cpp
 *
 *  Created on: Aug 29, 2024
 *      Author: leijon
 */


#include <vector>
#include <iostream>
#include "ivsSessions.h"

struct ListItems{
	std::string	item;
	bool		visible;
};


ivsSessions::ivsSessions(const char* _ptr, unsigned long _size)
{
	int				listCounter	= 0;
	unsigned long	c			= 0;
	std::string		buffer;

	// create the ivsList using the vector class
	// this makes it easier to manage dynamic lists
	//std::vector<std::string>	ivsList;
	std::vector<ListItems>		ivsListItems;

	// read in the contents from *_ptr
	// one item per line (search for the linefeeds)
	// delete unnecessary stuff, like heading and footer
	// present the list to the user, with filter options

	std::cout << "Size of *_ptr: " << _size << std::endl;
	buffer.clear();

	while(c < _size){

		buffer.append(1, *_ptr);

		if(*_ptr == '\r'){

			//std::cout << buffer;

			//ivsList.push_back(buffer);
			ivsListItems.push_back({buffer, true});

			listCounter++;
			buffer.clear();
		}

		c++;
		*_ptr++;


	} // while(c <= _size)

	// print the entire list
	//std::cout << "Number of elements in the ivsList: " << ivsList.size() << std::endl;
	std::cout << "Number of elements in the ivsListItems: " << ivsListItems.size() << std::endl;
	for(int i = 0; i < (int)ivsListItems.size(); i++){
		std::cout << ivsListItems[i].item;
	};

	std::cout << std::endl << "Number of items: " << listCounter << std::endl;

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

