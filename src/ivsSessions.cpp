/*
 * ivsSessions.cpp
 *
 *  Created on: Aug 29, 2024
 *      Author: leijon
 */
#pragma GCC diagnostic ignored "-Wunused-value" *_ptr


#include <vector>
#include <iostream>
//#include <unistd.h>
#include "ivsSessions.h"



void ivsSessions::run(void)
{
	// set up the screen
	hideCursor();
	clearScreen();
	printHeaders();
	printSearchFields();
	printItemList();
	showCursor();

}



void ivsSessions::clearAllBuffers(void)
{
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
}



void ivsSessions::printHeaders(void)
{
	// print the heading to screen
	if(intensives){
		std::cout << INTENSIVE_HEADING_1 << std::endl;
		std::cout << INTENSIVE_HEADING_2 << std::endl;
	}
	else{
		std::cout << NORMAL_HEADING_1 << std::endl;
		std::cout << NORMAL_HEADING_2 << std::endl;
	}
}



void ivsSessions::clearScreen(void)
{
	// Clear the terminal
	std::cout << "\033[2J\033[1;1H";
}



void ivsSessions::printSearchFields(void)
{
	std::string	textColor;

	textColor = "\033[31;47m";
	std::cout << textColor;
	std::cout << "Input field" << std::endl;

}



void ivsSessions::printItemList(void)
{
	// "\033[Effects;Colours;Backgrounds;Extra coloursm"
	std::string	textColor;	// = "\033[33m";

	//clearScreen();
	//printSearchFields();

	for(int i = 0; i < (int)ivsListItems.size(); i++){
		if(i == 0){
			textColor = "\033[30;102m";	//
		}
		else/* if(i > 0)*/{
			textColor = "\033[40;00m";		// white text, default background
		}
		std::cout	<< textColor
					<< ivsListItems[i].sessionType
					<< ivsListItems[i].date
					<< ivsListItems[i].sessionCode
					<< ivsListItems[i].doy
					<< ivsListItems[i].time
					<< ivsListItems[i].dur
					<< ivsListItems[i].includedStations
					<< ivsListItems[i].excludedStations
					<< ivsListItems[i].sked
					<< ivsListItems[i].corr
					<< ivsListItems[i].status
					<< ivsListItems[i].dbcCode
					<< ivsListItems[i].subm
					<< ivsListItems[i].del
					<< std::endl;
	}
	textColor = "\033[0m";
	std::cout << "\033[36mNumber of elements in the session list: " << ivsListItems.size() << std::endl;
}



ivsSessions::ivsSessions(const char* _ptr, unsigned long _size, bool _intensives)
{
	unsigned long	c		= 0;
	bool			quit	= false;


	// clear all buffers
	clearAllBuffers();

	intensives = _intensives;

	startIndex	= 0;
	endIndex	= 1;

	// scan forward to the first occurence of '|', to put us at the start of the actual sessions
	while(*_ptr != '|'){
		*_ptr++;
		c++;
	}

	// print the heading to screen
	//printHeaders();

    // traverse the *_ptr, assigning each line to an element in a list
    while(!quit){

		if(*_ptr == '\r'){
			buffer.append(1, *_ptr);

			// We're at the start of the buffer and the first character is '|'
			// This corresponds to startIndex = 0;
			// Now I must scan the buffer for the next occurence of '|'
			// And store that index in endIndex
			// Unless this is a divider, then the whole string is '---'
			if(buffer[0] != '-'){
			while(buffer[endIndex] != '|')
				endIndex++;
			_sessionType.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;

			_date.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_sessionCode.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_doy.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_time.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_dur.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_includedStations.append(buffer, startIndex, (endIndex - startIndex));

			//startIndex = endIndex;
			//endIndex++;
			//while(buffer[endIndex] != '|')
			//	endIndex++;
			//_excludedStations.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_sked.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_corr.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_status.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_dbcCode.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_subm.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_del.append(buffer, startIndex, (endIndex - startIndex + 1));

			ivsListItems.push_back({_sessionType,
				                    _date,
									_sessionCode,
									_doy,
									_time,
									_dur,
									_includedStations,
									_excludedStations,
									_sked,
									_corr,
									_status,
									_dbcCode,
									_subm,
									_del,
									true});


			}

			// clear all buffers
			clearAllBuffers();

			// reset indexes
			startIndex	= 0;
			endIndex	= 1;

			// advance pointer
			*_ptr++;
		}
		else{
			// add the *_ptr to the buffer
			buffer.append(1, *_ptr);
		}
		*_ptr++;
		c++;

		if((*_ptr) == '#'){
			quit = true;
		}
		if(c >= _size)
			quit = true;
	}
}



ivsSessions::~ivsSessions()
{
	// TODO Auto-generated destructor stub
}

