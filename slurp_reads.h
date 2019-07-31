/*
 * slurp_reads.h
 *
 *  Created on: Jul 31, 2019
 *      Author: eli_lab
 */

#ifndef SLURP_READS_H
#define SLURP_READS_H

#include <map>
#include <string>

#include "parameters.h"

std::map< std::string, unsigned long long int > slurp( const Parameters& );

#endif /* SLURP_READS_H */
