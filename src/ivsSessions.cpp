/*
 * ivsSessions.cpp
 *
 *  Created on: Aug 29, 2024
 *      Author: leijon
 */
#pragma GCC diagnostic ignored "-Wunused-value" *_ptr


#include <vector>
#include <iostream>
//#include <signal.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "ivsSessions.h"



void ivsSessions::run(void)
{
	// set up the screen
	clearScreen();
	hideCursor();
	terminalSize();

	//print(1, 33, "columns: ");
	//print(10, 33, columns);
	//print(13, 33, ", rows: ");
	//print(21, 33, rows);
	//print(1, 34, "Jon Leithe");

	printHeaders();
	printSearchFields();
	printItemList();

	sleep(3);
	showCursor();
	sleep(3);
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
		print(1, 1, INTENSIVE_HEADING_1);
		print(1, 2, INTENSIVE_HEADING_2);
		//std::cout << INTENSIVE_HEADING_1 << std::endl;
		//std::cout << INTENSIVE_HEADING_2 << std::endl;
	}
	else{
		print(1, 1, NORMAL_HEADING_1);
		print(1, 2, NORMAL_HEADING_2);
		//std::cout << NORMAL_HEADING_1 << std::endl;
		//std::cout << NORMAL_HEADING_2 << std::endl;
	}
	std::cout << std::endl;
}



void ivsSessions::clearScreen(void)
{
	// Clear the terminal
	std::cout << "\033[2J\033[1;1H";
}



void ivsSessions::printSearchFields(void)
{
	int	startx	= 0;
	int	endx	= 0;
	int	index	= 0;

	while(ivsListItems[0].sessionType[index] == '|')
		index++;
	startx = index;

	//std::cout << "startx: " << startx << std::endl;

	//print(2, 3, "Jon Leithe");

	//std::string	textColor;
	/*
	textColor = "\033[31;47m";
	std::cout << textColor;
	std::cout << "Input field" << std::endl;
	*/

}



void ivsSessions::terminalSize(void)
{
	struct	winsize	ws;

	// Use ioctl to get the window size
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
		std::cerr << "Error: Unable to get terminal size" << std::endl;
		return;
	}

	//clearScreen();

    // Assign terminal size to variables
    columns	= ws.ws_col;
    rows	= ws.ws_row;
}



void ivsSessions::print(int _x, int _y, std::string _text)
{
	std::cout << "\033[" << _y << ";" << _x << "H" << _text << std::endl;
}



void ivsSessions::print(int _x, int _y, int _number)
{
	std::cout << "\033[" << _y << ";" << _x << "H" << _number << std::endl;
}



// TODO: print the list at the desired location
//
// TODO: keeping track of:
//							- how big screen I have
//							- which items are visible on the display
//							- which item is highlighted
//
// TODO:
// TODO:
void ivsSessions::printItemList(void)
{
	// "\033[Effects;Colours;Backgrounds;Extra colours m"
	std::string	textColor;	// = "\033[33m";

	ivsListItems[20].highlighted = true;

	int x = 1;
	int y = 4;
	for(int i = 0; i < (int)ivsListItems.size(); i++){
		/*
		if(i == 0){
			textColor = "\033[30;102m";	//
		}
		else{
			textColor = "\033[40;00m";		// white text, default background
		}
		*/
		if(ivsListItems[i].highlighted){
			textColor = "\033[30;102m";	//
		}
		else{
			textColor = "\033[40;00m";		// white text, default background
		}
		print(x, y, textColor);
		print(x, y, ivsListItems[i].sessionType
				  + ivsListItems[i].date
				  + ivsListItems[i].sessionCode
				  + ivsListItems[i].doy
				  + ivsListItems[i].time
				  + ivsListItems[i].dur
				  + ivsListItems[i].includedStations
				  + ivsListItems[i].excludedStations
				  + ivsListItems[i].sked
				  + ivsListItems[i].corr
				  + ivsListItems[i].status
				  + ivsListItems[i].dbcCode
				  + ivsListItems[i].subm
				  + ivsListItems[i].del
				  );
		y++;
		//x += ivsListItems[i].sessionType.size();
		//print(x, 4, ivsListItems[i].date);
		/*
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
		*/
	}
	//textColor = "\033[0m";
	//std::cout << "\033[36mNumber of elements in the session list: " << ivsListItems.size() << std::endl;

	//buffer.clear();
	//buffer.append("\033[36mNumber of elements in the session list: ");
	//print(1, (rows-3), buffer);
	//print(41, (rows-3), ivsListItems.size());

	//buffer.append(ivsListItems.size());
	//buffer.append(std::endl);
	//print(1, (rows-1), buffer);
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
									true,
									false });


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
	showCursor();
}

