/*
 * ivsSessions.h
 *
 *  Created on: Aug 29, 2024
 *      Author: leijon
 */

#ifndef INC_IVSSESSIONS_H_
#define INC_IVSSESSIONS_H_

//#include "fileoperations.h"
//#include "sessionlist.h"
#include <vector>
#include <termios.h>


#define INTENSIVE_HEADING_1	"   SESSION      DATE     SESSION    DOY TIME   DUR       STATIONS                             SKED CORR  STATUS  DBC  SUBM DEL"
#define INTENSIVE_HEADING_2	"     TYPE     yyyymmdd     CODE     ddd hh:mm  h:mm                                                     yyyymmdd CODE      days"
#define NORMAL_HEADING_1	"   SESSION      DATE     SESSION    DOY TIME   DUR                         STATIONS                        SKED CORR  STATUS  DBC  SUBM DEL"
#define NORMAL_HEADING_2	"     TYPE     yyyymmdd     CODE     ddd hh:mm  h:mm                                                                  yyyymmdd CODE      days"

#define CTRL_KEY(k) ((k) & 0x1f)



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
	bool			highlighted;
};



struct SearchFields{
	bool	active;
	short	xLocation, yLocation, cursorLocation;

	std::string	textColor;
	std::string	searchText;
};



class ivsSessions{

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
	std::string		buffer, textColor;

	int				startIndex, endIndex;
	int				columns, rows;
	int				listStartRow, listEndRow;

	bool			_visible, intensives;

	std::vector<SessionList>	ivsListItems;
	std::vector<SearchFields>	searchFieldList;

	struct termios orig_termios;



	// inline private functions
	void	hideCursor(void)			{ std::cout << "\033[?25l"; }
	void	showCursor(void)			{ std::cout << "\033[?25h"; }
	// std::cout << "\033[10;20H";     // Move cursor to row 10, column 20


	void	print(int _x, int _y, std::string _text);
	void	print(int _x, int _y, int _number);
	void	clearScreen(void);
	void	moveCursor(int _x, int _y);
	void	terminalSize(void);
	void	enableRawMode(void);
	void	disableRawMode(void);
	void	die(const char *s);
	char	readKey(void);
	void	processKeypress(void);
	void	refreshScreen(void);

	void	clearAllBuffers(void);
	void	printHeaders(void);
	void	printItemList(int _startItem);
	void	setupSearchFields(void);
	void	printSearchFields(void);

public:
	ivsSessions(const char* _ptr, unsigned long _size, bool _intensives);
	virtual ~ivsSessions();

	void	run(void);
};

#endif /* INC_IVSSESSIONS_H_ */
