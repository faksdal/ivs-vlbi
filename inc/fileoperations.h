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

//using namespace std;


#define MAXSEARCHTERMS	16



class fileoperations {

private:
	bool			fo_verbose;

	std::string		fo_inputBuffer;
	std::string		fo_outputBuffer;

	std::string		fo_inputFileName;
	std::string		fo_outputFileName;

	std::ifstream	fo_inputFileStream;
	std::ofstream	fo_outputFileStream;

	std::streampos	fo_inputFileSize;
	std::streampos	fo_inputFilePosition;
	std::streampos	fo_outputFilePosition;

	std::streamsize	MAXLINELENGTH = 256;

	unsigned long	fo_inputBufferIndex;



	//size_t	fo_findAntenna(std::string _antenna, size_t _startPos);
	//bool	fo_antennaRemovedFromSession(std::string _antenna, size_t _startPos);

	//streampos	fo_gotoInputPosition(streampos _newFilePosition, ifstream _fo_inputFileStream);
	//streampos	fo_gotoOutputPosition(streampos _newFilePosition, ofstream _fo_outputFileStream);


protected:

public:
	fileoperations(std::string _inputFileName, std::string _outputFileName, bool _verbose);
	virtual ~fileoperations();

	unsigned long	fo_resetInputFilePos(void);
	void			fo_readFromInputFile(void);

	//inline unsigned long	fo_getInputFileSize(void)			{ return (unsigned long)fo_inputFileSize; }
	//inline std::streampos	fo_getCurrentInputFilePos(void)		{ return fo_inputFilePosition; }
	//inline std::streampos	fo_getCurrentOutputFilePos(void)	{ return fo_outputFilePosition;	}


	//
	//void		fo_parseInputBuffer(std::string _antennaName);

	//void		printInputBufferToScreen(void) { cout << fo_inputBuffer << endl; }

	/*inline unsigned long	getNumberOfSearchHits(void)		{ return numberOfSearchHits;	}

	//inline unsigned long	resetInputFilePos(void)			{ inputFile.seekg(0, ios::beg);	return(inputFile.tellg()); }


	std::string getOutputFileName(bool _printToScreen);
	std::string getInputFileName(bool _printToScreen);

	//void			readFile(void);

	unsigned long	find(unsigned long _startPosition, std::string _searchstd::string);


	//std::string			fread(unsigned long _startPosition, unsigned long _nbytes);

	*/
};



#endif /* INC_FILEOPERATIONS_H_ */
