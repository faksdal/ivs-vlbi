/*
 * sessionlist.h
 *
 *  Created on: Aug 29, 2024
 *      Author: leijon
 *
 *       SESSION      DATE     SESSION    DOY TIME   DUR                         STATIONS                        SKED CORR  STATUS  DBC  SUBM DEL
           TYPE     yyyymmdd     CODE     ddd hh:mm  h:mm                                                                  yyyymmdd CODE      days
 */

#ifndef INC_SESSIONLIST_H_
#define INC_SESSIONLIST_H_

#include <string>



class sessions{
	std::string	s_sessionType;
	long int	s_date;
	std::string	s_sessionCode;
	int			s_doy;
	int			s_time;
	int			s_duration;
	std::string	s_stationsIncluded;
	std::string	s_stationsExcluded;
	std::string	s_scheduler;
	std::string	s_correlator;
	std::string	s_status;
	std::string	s_dbcCode;
	std::string	s_subm;
	int			s_del;

public:
	//sessions();
	//virtual ~sessions();
};



class sessionList{

	sessions*	s;

public:
	//sessionList();
	//virtual ~sessionList();

	sessions*	sl_add(	std::string	_sessionType,
						long int	_date,
						std::string	s_sessionCode,
						int			_doy,
						int			_time,
						int			_duration,
						std::string	_stationsIncluded,
						std::string	_stationsExcluded,
						std::string	_scheduler,
						std::string	_correlator,
						std::string	_status,
						std::string	_dbcCode,
						std::string	_subm,
						int			_del);
};

#endif /* INC_SESSIONLIST_H_ */
