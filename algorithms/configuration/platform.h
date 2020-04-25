//-----------------------------------------------------------------------------------------------------------
/*!	\file kaos/kernel/system/configuration/platform/platform.h
	\brief Flags fuer Betriebssysteme
	\version 0.1
	\date 6.2.2003
	\author Christian Oberholzer

	Setzt die Flags fuer die verschiedenen Betriebssysteme
*/
//-----------------------------------------------------------------------------------------------------------
#ifndef KKERNEL_SYSTEM_CONFIGURATION_PLATFORM_PLATFORM_H
#define KKERNEL_SYSTEM_CONFIGURATION_PLATFORM_PLATFORM_H

#if defined(_WIN32) || defined(_WIN64) || defined(KAOS_WIN32) || defined(KAOS_WIN64) || defined(KAOS_WINRT32) || defined(KAOS_WINRT64)
#	include <winsock2.h>
#	include <Windows.h>
#endif

//-----------------------------------------------------------------------------------------------------------
#if !defined(KAOS_WIN32) && !defined(KAOS_WIN64) && !defined(KAOS_LINUX)

#	if defined(WINAPI_FAMILY_PARTITION)
#		if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) && defined(_WIN64)
#			define KAOS_WINRT
#			define KAOS_WINRT64
#			define KAOS_WIN
#		elif !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) && defined(_WIN32)
#			define KAOS_WINRT
#			define KAOS_WINRT32
#			define KAOS_WIN
#		elif defined(_WIN64)
#			define KAOS_WIN64
#			define KAOS_WIN
#		elif defined(_WIN32)
#			define KAOS_WIN32
#			define KAOS_WIN
#		elif
#			error Undefined application partition!
#		endif
#	elif defined(_WIN64)
#		define KAOS_WIN64
#		define KAOS_WIN
#	elif defined(_WIN32)
#		define KAOS_WIN32
#		define KAOS_WIN
#	elif defined(__ANDROID__)
#		define KAOS_ANDROID
#   elif __APPLE__
#       include "TargetConditionals.h"
#       if TARGET_IPHONE || TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#           define KAOS_IOS
#       elif TARGET_OS_MAC
#           define KAOS_MAC
#       endif
#	endif

#	if defined(__linux__)
#		define KAOS_LINUX
#	endif
#endif

#if !defined(KAOS_WIN32) && !defined(KAOS_WIN64) && !defined(KAOS_WINRT64) && !defined(KAOS_WINRT32) && !defined(KAOS_LINUX) && !defined(KAOS_ANDROID) && !defined(KAOS_IOS) && !defined(KAOS_MAC)
#	error Ein Betriebssystem muss definiert sein! kconfig.h sollte dementsprechend angepasst werden!
#endif




//-----------------------------------------------------------------------------------------------------------
#if defined(KAOS_WIN32)
#	include <windows.h>

#	undef CreateFont
#	undef DrawText
#	undef DeleteFont

#	define KAOS_SYSTEM "win32"
#	define KAOS_PLATFORM_STRING "Microsoft Windows (32bit-Edition)"

#	ifndef WIN32_LEAN_AND_MEAN
#		define WIN32_LEAN_AND_MEAN
#	endif

#	if defined(KAOS_GNUC)
#		define KAOS_EXPORT __attribute__((dllexport))
#		define KAOS_IMPORT __attribute__((dllimport))
#	elif defined(KAOS_INTEL_CPP) || defined(KAOS_VC) || defined(KAOS_BORLANDC) || defined(KAOS_MWERKS)
#		define KAOS_EXPORT __declspec(dllexport)
#		define KAOS_IMPORT __declspec(dllimport)
#	endif

//-----------------------------------------------------------------------------------------------------------
#elif defined(KAOS_WIN64)
#	include <windows.h>

#	undef CreateFont
#	undef DrawText
#	undef DeleteFont

#	define KAOS_SYSTEM "win64"
#	define KAOS_PLATFORM_STRING "Microsoft Windows (64bit-Edition)"

#	ifndef WIN32_LEAN_AND_MEAN
#		define WIN32_LEAN_AND_MEAN
#	endif

#	if defined(KAOS_GNUC)
#		define KAOS_EXPORT __attribute__((dllexport))
#		define KAOS_IMPORT __attribute__((dllimport))
#	elif defined(KAOS_INTEL_CPP) || defined(KAOS_VC) || defined(KAOS_BORLANDC) || defined(KAOS_MWERKS)
#		define KAOS_EXPORT __declspec(dllexport)
#		define KAOS_IMPORT __declspec(dllimport)
#	endif

//-----------------------------------------------------------------------------------------------------------
#elif defined(KAOS_WINRT32)
#	include <windows.h>

#	undef CreateFont
#	undef DrawText
#	undef DeleteFont

#	define KAOS_SYSTEM "winrt32"
#	define KAOS_PLATFORM_STRING "Microsoft Windows Store App (32bit-Edition)"

#	ifndef WIN32_LEAN_AND_MEAN
#		define WIN32_LEAN_AND_MEAN
#	endif

#	if defined(KAOS_GNUC)
#		define KAOS_EXPORT __attribute__((dllexport))
#		define KAOS_IMPORT __attribute__((dllimport))
#	elif defined(KAOS_INTEL_CPP) || defined(KAOS_VC) || defined(KAOS_BORLANDC) || defined(KAOS_MWERKS)
#		define KAOS_EXPORT __declspec(dllexport)
#		define KAOS_IMPORT __declspec(dllimport)
#	endif

//-----------------------------------------------------------------------------------------------------------
#elif defined(KAOS_WINRT64)
#	include <windows.h>

#	undef CreateFont
#	undef DrawText
#	undef DeleteFont

#	define KAOS_SYSTEM "winrt64"
#	define KAOS_PLATFORM_STRING "Microsoft Windows Store App (64bit-Edition)"

#	ifndef WIN32_LEAN_AND_MEAN
#		define WIN32_LEAN_AND_MEAN
#	endif

#	if defined(KAOS_GNUC)
#		define KAOS_EXPORT __attribute__((dllexport))
#		define KAOS_IMPORT __attribute__((dllimport))
#	elif defined(KAOS_INTEL_CPP) || defined(KAOS_VC) || defined(KAOS_BORLANDC) || defined(KAOS_MWERKS)
#		define KAOS_EXPORT __declspec(dllexport)
#		define KAOS_IMPORT __declspec(dllimport)
#	endif

//-----------------------------------------------------------------------------------------------------------
#elif defined(KAOS_LINUX)
#	define KAOS_SYSTEM "linux"
#	define KAOS_PLATFORM_STRING "Linux"
#	define KAOS_IMPORT
#	define KAOS_EXPORT

#	if !defined(TRUE)
#		define TRUE (1)
#	endif

#	if !defined(FALSE)
#		define FALSE (0)
#	endif

#	if !defined(NULL)
#		define NULL (0)
#	endif

//-----------------------------------------------------------------------------------------------------------
#elif defined(KAOS_IOS)
#	define KAOS_SYSTEM "ios"
#	define KAOS_PLATFORM_STRING "iOS"
#	define KAOS_IMPORT
#	define KAOS_EXPORT

#	if !defined(TRUE)
#		define TRUE (1)
#	endif

#	if !defined(FALSE)
#		define FALSE (0)
#	endif

#	if !defined(NULL)
#		define NULL (0)
#	endif

//-----------------------------------------------------------------------------------------------------------
#elif defined(KAOS_MAC)
#	define KAOS_SYSTEM "osX"
#	define KAOS_PLATFORM_STRING "OS X"
#	define KAOS_IMPORT
#	define KAOS_EXPORT

#	if !defined(TRUE)
#		define TRUE (1)
#	endif

#	if !defined(FALSE)
#		define FALSE (0)
#	endif

#	if !defined(NULL)
#		define NULL (0)
#	endif

//-----------------------------------------------------------------------------------------------------------
#else
#	define KAOS_SYSTEM "other"
#	error Das Betriebssystem muss bekannt sein! Es sollte in diesem Fall in kconfig.h definiert werden!

#endif

#endif // KKERNEL_SYSTEM_CONFIGURATION_PLATFORM_PLATFORM_H
