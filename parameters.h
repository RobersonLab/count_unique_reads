/*
 * parameters.h
 *
 *  Created on: Jul 31, 2019
 *      Author: eli_lab
 */

// standard libraries
#include <string>

#ifndef PARAMETERS_H_
#define PARAMETERS_H_

class Parameters {
	public:
		Parameters( int argc, char *argv[] );
		virtual ~Parameters();

		const std::string& getFastqFile() const {
			return fastq_file;
		}

		void setFastqFile( const std::string& inputFile ) {
			fastq_file = inputFile;
		}

		const unsigned int getCountThreshold() const {
			return count_threshold;
		}

		void setCountThreshold( int threshold ) {
			count_threshold = threshold;
		}

	private:
		// input files
		std::string fastq_file;

		unsigned long long int count_threshold;
};

void printUsage();

#endif /* PARAMETERS_H_ */
