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
	std::string		date;
	std::string		sessionCode;
	std::string		doy;
	std::string		time;
	std::string		dur;
	std::string		includedStations;
	std::string		excludedStations;
	std::string		sked;
	std::string		corr;
	std::string		status;
	std::string		dbcCode;
	std::string		subm;
	std::string		del;

	bool			visible;
};


ivsSessions::ivsSessions(const char* _ptr, unsigned long _size)
{
	int				listCounter	= 0;
	unsigned long	c			= 0;
	std::string		buffer;
	bool			quit		= false;

	std::string		_sessionType;
	std::string		_date;
	std::string		_sessionCode;
	std::string		_doy;
	std::string		_time;
	std::string		_dur;
	std::string		_includedStations;
	std::string		_excludedStations;
	std::string		_sked;
	std::string		_corr;
	std::string		_status;
	std::string		_dbcCode;
	std::string		_subm;
	std::string		_del;

	bool			_visible;

	// create the ivsList using the vector class
	// this makes it easier to manage dynamic lists
	//std::vector<ListItems> ivsListItems;
	std::vector<SessionList> ivsListItems;

	// read in the contents from *_ptr
	// one item per line (search for the linefeeds)
	// delete unnecessary stuff, like heading and footer
	// present the list to the user, with filter options

	buffer.clear();
	_sessionType.clear();
	_date.clear();
	_sessionCode.clear();
	_doy.clear();
	_time.clear();
	_dur.clear();
	_includedStations.clear();
	_excludedStations.clear();
	_sked.clear();
	_corr.clear();
	_status.clear();
	_dbcCode.clear();
	_subm.clear();
	_del.clear();

	// scan forward to the first occurence of '|', to put us at the start of the actual sessions
	while(*_ptr != '|'){
		*_ptr++;
		c++;
	}

	// print the heading to screen
	std::cout << "   SESSION      DATE     SESSION    DOY TIME   DUR                         STATIONS                        SKED CORR  STATUS  DBC  SUBM DEL" << std::endl;
    std::cout << "     TYPE     yyyymmdd     CODE     ddd hh:mm  h:mm                                                                  yyyymmdd CODE      days" << std::endl;

    // traverse the *_ptr, assigning each line to an element in a list
    while(!quit){

		if(*_ptr == '\r'){
			// add the text "NEWLINE", and the *_ptr to the buffer
			//buffer.append("NEWLINE");
			buffer.append(1, *_ptr);
			//std::cout << "NEWLINE";// << std::endl;
			//std::cout << *_ptr;// << std::endl;
			for(int i = 0; i < 13; i++){
				//std::cout << buffer[i];
			}
			for(int i = 13; i < 22; i++){
				//std::cout << buffer[i];
			}

			// TODO: dynamically set the boundries for each field
			// TODO: as the intensive and regular schedule files differ in format
			_sessionType.append(buffer, 0, 13);
			_date.append(buffer, 13, 9);
			_sessionCode.append(buffer, 22, 13);
			_doy.append(buffer, 35, 4);

			_time.append(buffer, 39, 6);
			_dur.append(buffer, 45, 6);

			_includedStations.append(buffer, 51, 55);
			//_excludedStations.append(buffer, 51, 55);
			_sked.append(buffer, 106, 5);
			_corr.append(buffer, 111, 5);
			_status.append(buffer, 116, 9);
			_dbcCode.append(buffer, 125, 5);
			_subm.append(buffer,  130, 5);
			_del.append(buffer, 135, 6);


			std::cout	<< _sessionType
						<< _date
						<< _sessionCode
						<< _doy
						<< _time
						<< _dur
						<< _includedStations
						<< _excludedStations
						<< _sked
						<< _corr
						<< _status
						<< _dbcCode
						<< _subm
						<< _del;

			// print the string to screen
			std::cout << std::endl;

			// clear all buffers
			buffer.clear();
			_sessionType.clear();
			_date.clear();
			_sessionCode.clear();
			_doy.clear();
			_time.clear();
			_dur.clear();
			_includedStations.clear();
			_excludedStations.clear();
			_sked.clear();
			_corr.clear();
			_status.clear();
			_dbcCode.clear();
			_subm.clear();
			_del.clear();

			// advance pointer to string
			*_ptr++;
		}
		else{
			// add the *_ptr to the buffer
			buffer.append(1, *_ptr);
			//std::cout << *_ptr;// << std::endl;
		}
		*_ptr++;
		c++;

		if((*_ptr) == '#'){
			quit = true;
		}
		if(c >= _size)
			quit = true;
	}

	/*
	while(c < _size){

		//std::cout << "*_ptr = " << *_ptr << std::endl;

		buffer.append(1, *_ptr);

		// if we encounter a newline, we add the buffer to the list
		// and clear he buffer, making it ready for a new line
		if(*_ptr == '\r'){

			// terminate string
			buffer.append(1, '\0');

			int start = 0;
			// skip whitespace in start of buffer
			while(buffer[start] == ' ')
				start++;



			// string& append (const string& str, size_t subpos, size_t sublen);
			_sessionType.append(buffer, start, 13);
			_date.append(buffer, 13, 9);

			//std::cout << buffer << std::endl;
			//std::cout << buffer[15] << buffer[16] << std::endl;

			std::cout << _sessionType << std::endl;
			std::cout << _date << std::endl;

			ivsListItems.push_back({_sessionType, _date, true});

			//std::cout << buffer;

			// search the buffer for matching stations
			// buffer (3) size_t find (const char* s, size_t pos, size_t n) const;
			// https://cplusplus.com/reference/string/string/find/

			//if( (buffer.find("Ns", 52, 2) == std::string::npos) || (buffer.find("Nn", 52, 2) == std::string::npos) )
			//	ivsListItems.push_back({buffer, false});
			//else
			//	ivsListItems.push_back({buffer, true});


			listCounter++;
			buffer.clear();

			_sessionType.clear();
			_date.clear();

		} // if(*_ptr == '\r')

		c++;
		*_ptr++;

		// check for end of list, we don't need to copy that text
		if((*_ptr) == '#'){
			c = _size;
		}


	} // while(c <= _size)
	*/


	//std::cout << std::endl;

	// print the entire list
	//std::cout << "Number of elements in the ivsList: " << ivsList.size() << std::endl;

	//std::cout << "Number of elements in the ivsListItems: " << ivsListItems.size() << std::endl;

	/*
	for(int i = 0; i < (int)ivsListItems.size(); i++){
		//std::cout << ivsListItems[i].visible;
		//std::cout << "$ ";
		//if(ivsListItems[i].visible)
			std::cout	<< ivsListItems[i].sessionType
						<< ivsListItems[i].date;
	};
	*/


	//std::cout << std::endl << "Number of items: " << listCounter << std::endl;

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

