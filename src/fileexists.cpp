/*
 * fileexists.cpp
 *
 *  Created on: May 21, 2024
 *      Author: leijon
 */

//
// TODO - describe what we're calculating here...
//

#include <sys/stat.h>
#include <unistd.h>
#include <string>



bool fileexists(const std::string& name)
{
	struct stat buffer;
	return(stat(name.c_str(), &buffer) == 0);
}
