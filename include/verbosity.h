/*
 * verbosity.h
 *
 *  Created on: Jun 1, 2015
 *      Author: ilg
 */

#ifndef VERBOSITY_H_
#define VERBOSITY_H_

#include "config-host.h"

#if defined(CONFIG_VERBOSE)
typedef enum {
	VERBOSITY_NONE = 0,
	VERBOSITY_COMMON,
	VERBOSITY_DETAILED,
	VERBOSITY_DEBUG
} verbosity_t;

extern verbosity_t verbosity_level;

#endif

#endif /* VERBOSITY_H_ */
