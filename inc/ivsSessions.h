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
/*
 *
 */

#define INTENSIVE_HEADING_1	"   SESSION      DATE     SESSION    DOY TIME   DUR       STATIONS                             SKED CORR  STATUS  DBC  SUBM DEL"
#define INTENSIVE_HEADING_2	"     TYPE     yyyymmdd     CODE     ddd hh:mm  h:mm                                                     yyyymmdd CODE      days"
#define NORMAL_HEADING_1	"   SESSION      DATE     SESSION    DOY TIME   DUR                         STATIONS                        SKED CORR  STATUS  DBC  SUBM DEL"
#define NORMAL_HEADING_2	"     TYPE     yyyymmdd     CODE     ddd hh:mm  h:mm                                                                  yyyymmdd CODE      days"



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
	std::string		buffer;

	int				startIndex, endIndex;

	bool			_visible, intensives;

	// create the ivsList using the vector class
	// this makes it easier to manage dynamic lists
	//std::vector<ListItems> ivsListItems;
	std::vector<SessionList> ivsListItems;


	// inline private functions
	void	hideCursor(void) {std::cout << "\033[?25l";}
	void	showCursor(void) {std::cout << "\033[?25h";}

	void	clearScreen(void);
	void	clearAllBuffers(void);
	void	printHeaders(void);
	void	printItemList(void);
	void	printSearchFields(void);

public:
	ivsSessions(const char* _ptr, unsigned long _size, bool _intensives);
	virtual ~ivsSessions();

	void	run(void);
};

#endif /* INC_IVSSESSIONS_H_ */
