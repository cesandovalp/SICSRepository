/*
 * trace.h
 *
 *  Created on: May 27, 2014
 *      Author: mirt
 */

#ifndef TRACE_H_
#define TRACE_H_

#include <string>
#include <fstream>
#include <type/Matrix.h>

using namespace std;

/**
 * Trace class for constructing execution and error logs onto files.
 * Create a trace with a file to trace to that file
 * when logging errors onto a trace the error logs onto the file asociated
 * trace object can take ostreams, so any output class of cpp can output to the trace
 * */
class Trace {
	const char * filename;

public:
	Trace( const char * );

	template<typename T>
	void operator() ( Matrix<T>&);
	template<typename T>
	void operator() ( T );

	virtual ~Trace();
	const char* getFilename() const;
	void setFilename(const char* filename);
};


template<typename T>
void Trace::operator() ( Matrix<T> & message ) {

	ofstream file;
	file.open ( filename, ofstream::app );

	file << message;

	file.close ();
}

template<typename T>
void Trace::operator ()(T message) {
	ofstream file;
	file.open ( filename, ofstream::app );

	file << message;

	file << endl;

	file.close ();
}


Trace::Trace( const char * filename ) {

	this->filename = filename;

}
Trace::~Trace() {
	// TODO Auto-generated destructor stub
}

const char* Trace::getFilename() const {
	return filename;
}

void Trace::setFilename(const char* filename) {
	this->filename = filename;
}

#endif /* TRACE_H_ */
