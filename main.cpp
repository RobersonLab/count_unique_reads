/*
 * main.cpp
 *
 *  Created on: Jul 31, 2019
 *      Author: eli_lab
 */

// standard template library
#include <iostream>
#include <map>
#include <string>

// project includes
#include "helper.h"
#include "parameters.h"
#include "slurp_reads.h"

int main ( int argc, char *argv[] )
{
	Parameters settings = Parameters( argc, argv );
	unsigned long long int min_count = settings.getCountThreshold();

	std::map< std::string, unsigned long long int > read_count_map = slurp( settings );

	std::cout << std::string( "IndexPair\tCount" ) << std::endl;

	for ( std::map< std::string, unsigned long long int >::const_iterator iter = read_count_map.begin(); iter != read_count_map.end(); ++iter ) {
		if ( iter->second >= min_count ) {
			std::cout << iter->first << std::string( "\t" ) << iter->second << std::endl;
		}
	}

	return 0;
}
