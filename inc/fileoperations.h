/*
 * FileOperations.h
 *
 *  Created on: May 7, 2024
 *      Author: leijon
 */

#ifndef INC_FILEOPERATIONS_H_
#define INC_FILEOPERATIONS_H_

#include <math.h>
#include <string>
#include <fstream>
#include <iostream>

//#include <sys/stat.h>
//#include <unistd.h>

using namespace std;


#define MAXSEARCHTERMS	16



class fileoperations {

private:
	bool			fo_verbose;

	string			fo_inputFileName;
	string			fo_outputFileName;

	ifstream		fo_inputFileStream;
	ofstream		fo_outputFileStream;

	streampos		fo_inputFileSize;
	streampos		fo_inputFilePosition;
	streampos		fo_outputFilePosition;


	//streampos	fo_gotoInputPosition(streampos _newFilePosition, ifstream _fo_inputFileStream);
	//streampos	fo_gotoOutputPosition(streampos _newFilePosition, ofstream _fo_outputFileStream);


protected:

public:
	fileoperations(string _inputFileName, string _outputFileName, bool _verbose);
	virtual ~fileoperations();

	inline unsigned long	fo_getInputFileSize(void)			{ return (unsigned long)fo_inputFileSize; }

	inline streampos		fo_getCurrentInputFilePos(void)		{ return fo_inputFilePosition; }
	inline streampos		fo_getCurrentOutputFilePos(void)	{ return fo_outputFilePosition;	}




	streampos	fo_readLineFromInputFile(streampos _newFilePosition, string &_readBuffer);

	/*inline unsigned long	getNumberOfSearchHits(void)		{ return numberOfSearchHits;	}

	//inline unsigned long	resetInputFilePos(void)			{ inputFile.seekg(0, ios::beg);	return(inputFile.tellg()); }


	string getOutputFileName(bool _printToScreen);
	string getInputFileName(bool _printToScreen);

	//void			readFile(void);

	unsigned long	find(unsigned long _startPosition, string _searchString);
	unsigned long	resetInputFilePos(void);

	//string			fread(unsigned long _startPosition, unsigned long _nbytes);

	*/
};



#endif /* INC_FILEOPERATIONS_H_ */
