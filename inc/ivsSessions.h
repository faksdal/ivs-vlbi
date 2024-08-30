/*
 * ivsSessions.h
 *
 *  Created on: Aug 29, 2024
 *      Author: leijon
 */

#ifndef INC_IVSSESSIONS_H_
#define INC_IVSSESSIONS_H_

#include "fileoperations.h"
#include "sessionlist.h"

/*
 *
 */
class ivsSessions: public sessionList, public sessions, public fileoperations{

	sessionList*	sl[];

public:
	ivsSessions(std::string _inputFileName, std::string _outputFileName, bool _verbose = false);
	virtual ~ivsSessions();
};

#endif /* INC_IVSSESSIONS_H_ */
