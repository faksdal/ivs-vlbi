/*
 * FileOperations.h
 *
 *  Created on: May 7, 2024
 *      Author: leijon
 */

#ifndef INC_FILEOPERATIONS_H_
#define INC_FILEOPERATIONS_H_

#include <string>
#include <fstream>
#include <iostream>

//#include <sys/stat.h>
//#include <unistd.h>

using namespace std;



class fileoperations {

private:
	ifstream	inputFileStream;
	ofstream	outputFileStream;

	string		inputFileName;
	string		outputFileName;


protected:

public:
	fileoperations(string _inputFileName, string _outputFileName);
	virtual ~fileoperations();

	/*
	//inline unsigned long	getInputFileSize(void)			{ return inputFileSize;			}
	inline unsigned long	getCurrentInputFilePos(void)	{ return currentInputFilePos;	}
	inline unsigned long	getNumberOfSearchHits(void)		{ return numberOfSearchHits;	}

	//inline unsigned long	resetInputFilePos(void)			{ inputFile.seekg(0, ios::beg);	return(inputFile.tellg()); }
	//inline unsigned long	getCurrentOutputFilePos(void)	{ return currentOutputFilePos;	}

	string getOutputFileName(bool _printToScreen);
	string getInputFileName(bool _printToScreen);

	//void			readFile(void);

	unsigned long	find(unsigned long _startPosition, string _searchString);
	unsigned long	resetInputFilePos(void);

	//string			fread(unsigned long _startPosition, unsigned long _nbytes);

	*/
};



#endif /* INC_FILEOPERATIONS_H_ */
