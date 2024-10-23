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

/*
 * SESSION      DATE     SESSION    DOY TIME   DUR                         STATIONS                        SKED CORR  STATUS  DBC  SUBM DEL
     TYPE     yyyymmdd     CODE     ddd hh:mm  h:mm                                                                  yyyymmdd CODE      days
 * */

struct SessionList{
	std::string		sessionType;
	unsigned long	date;
	std::string		sessionCode;
	int				doy;
	std::string		time;
	std::string		dur;
	std::string		includedStations;
	std::string		excludedStations;
	std::string		sked;
	std::string		corr;
	unsigned long	status;
	std::string		dbcCode;
	std::string		subm;
	int				del;
	bool			visible;
};


ivsSessions::ivsSessions(const char* _ptr, unsigned long _size)
{
	int				listCounter	= 0;
	unsigned long	c			= 0;
	std::string		buffer;

	std::string		_sessionType;
	unsigned long	_date;
	std::string		_sessionCode;
	int				_doy;
	std::string		_time;
	std::string		_dur;
	std::string		_includedStations;
	std::string		_excludedStations;
	std::string		_sked;
	std::string		_corr;
	unsigned long	_status;
	std::string		_dbcCode;
	std::string		_subm;
	int				_del;
	bool			_visible;

	// create the ivsList using the vector class
	// this makes it easier to manage dynamic lists
	std::vector<ListItems> ivsListItems;

	// read in the contents from *_ptr
	// one item per line (search for the linefeeds)
	// delete unnecessary stuff, like heading and footer
	// present the list to the user, with filter options

	buffer.clear();

	// scan forward to the first occurence of '|', to put us at the start of the actual sessions
	while(*_ptr != '|'){
		*_ptr++;
		c++;
	}

	while(c < _size){

		buffer.append(1, *_ptr);

		// if we encounter a newline, we add the buffer to the list
		// and clear he buffer, making it ready for a new line
		if(*_ptr == '\r'){

			// string& append (const string& str, size_t subpos, size_t sublen);
			_sessionType.append(buffer, 0, 142);
			ivsListItems.push_back({_sessionType, true});

			//std::cout << buffer;

			// search the buffer for matching stations
			// buffer (3) size_t find (const char* s, size_t pos, size_t n) const;
			// https://cplusplus.com/reference/string/string/find/
			/*
			if( (buffer.find("Ns", 52, 2) == std::string::npos) || (buffer.find("Nn", 52, 2) == std::string::npos) )
				ivsListItems.push_back({buffer, false});
			else
				ivsListItems.push_back({buffer, true});
			*/

			listCounter++;
			buffer.clear();
			_sessionType.clear();
		} // if(*_ptr == '\r')

		c++;
		*_ptr++;

		// check for end of list, we don't need to copy that text
		if((*_ptr) == '#'){
			c = _size;
		}


	} // while(c <= _size)


	std::cout << std::endl;

	// print the entire list
	//std::cout << "Number of elements in the ivsList: " << ivsList.size() << std::endl;

	std::cout << "Number of elements in the ivsListItems: " << ivsListItems.size() << std::endl;
	for(int i = 0; i < (int)ivsListItems.size(); i++){
		//std::cout << ivsListItems[i].visible;
		//std::cout << "$ ";
		//if(ivsListItems[i].visible)
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

