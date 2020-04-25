//-----------------------------------------------------------------------------------------------------------
/*!	\file kaos/types/configuration/system.h
	\brief Plattform- und Compilerspezifische Makros und Defines
	\version 0.1
	\date 1.8.2001
	\author Christian Oberholzer
	
	Plattform- und Compilerspezifische Makros und Defines

	Changes:
		- 13.05.2002 Christian Oberholzer Dokumentation erledigt.
*/
//-----------------------------------------------------------------------------------------------------------
#ifndef KAOS_TYPES_CONFIGURATION_CONFIG_H
#define KAOS_TYPES_CONFIGURATION_CONFIG_H

//-----------------------------------------------------------------------------------------------------------
// defines if this is a debug build or not
#if defined(_DEBUG) && !defined(KAOS_DEBUG)
#	define KAOS_DEBUG
#endif




//-----------------------------------------------------------------------------------------------------------
//configure some basic precompilation defines
//0 - no debugging wanted
//1 - very basic debug output
//2 - comprehensive debug output
//3 - all output, and a transcript of all messages
#if !defined(KAOS_SYSTEM_DEBUG_LEVEL)
#	if defined(KAOS_DEBUG)
		//Set the output level for 'DEBUG' builds
#		define KAOS_SYSTEM_DEBUG_LEVEL 3
#	else
//		Set the output level for 'RELEASE' builds.
//		Release output level is always 1, if this level generates too much
//		output then change the code!
#		define KAOS_SYSTEM_DEBUG_LEVEL 1
#	endif
#endif




//-----------------------------------------------------------------------------------------------------------
// use asserts on debug builds
#if defined(KAOS_DEBUG)
#	define KAOS_USE_ASSERTS
#endif




//-----------------------------------------------------------------------------------------------------------
#include "compiler.h"	// Compilerflags setzen
#include "platform.h"	// Betriebssysteme
#include "processor.h"	// Prozessorenflags setzen
#include "charset.h"	// character settings (unicode/ascii/mbcs)
#include "datatypes.h"	// declare kaos data types

// Version
#define KAOS_VERSION	KAOS_SYSTEM"-"\
						KAOS_COMPILER"-"\
						KAOS_CPU"-"\
						__DATE__"-"\
						__TIME__

// KAOS_EXPORT, KAOS_IMPORT, KAOS_INLINECLASS

#endif // KAOS_TYPES_CONFIGURATION_CONFIG_H
