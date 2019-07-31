/*
 * slurp_reads.cpp
 *
 *  Created on: Jul 31, 2019
 *      Author: eli_lab
 */

#include "parameters.h"
#include "slurp_reads.h"

#include <fstream>
#include <map>
#include <string>


std::map< std::string, unsigned long long int > slurp( const Parameters& settings ) {
	std::map< std::string, unsigned long long int > read_count_map;

	std::string fastq_fname = settings.getFastqFile();

	std::ifstream FASTQ_FH( fastq_fname.c_str(), std::ios::in );

	unsigned int fastq_line_part = 1;
	std::string current_index = "";

	while( !FASTQ_FH.eof() ) {
		std::getline( FASTQ_FH, current_index );

		if ( fastq_line_part == 2 ) {
			std::map< std::string, unsigned long long int >::iterator endIter = read_count_map.end();
			std::map< std::string, unsigned long long int >::iterator searchIter = read_count_map.find( current_index );

			if ( endIter == searchIter ) {
				// not found, start a new one
				read_count_map.insert( std::pair< std::string, unsigned long long int >( current_index, 1 ) );
			}
			else {
				read_count_map[ current_index ] += 1;
			}
		}
		else if ( fastq_line_part == 4 ) {
			fastq_line_part = 0;
		}
		++fastq_line_part;
	}

	FASTQ_FH.close();

	return read_count_map;
}
