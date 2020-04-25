//-----------------------------------------------------------------------------------------------------------
/*!	\file kaos/kernel/system/configuration/compiler/compiler.h
	\brief Flags für Compiler
	\version 0.1
	\date 6.2.2003, Christian Oberholzer, Implementierung
	\date 31.12.2007 Christian Oberholzer, Refactoring. (Verschiebung an neuen Ort, bessere Ordnung)

	Setzt die Flags für die verschiedenen Compiler
*/
//-----------------------------------------------------------------------------------------------------------
#ifndef KKERNEL_SYSTEM_CONFIGURATION_COMPILER_COMPILER_H
#define KKERNEL_SYSTEM_CONFIGURATION_COMPILER_COMPILER_H

//-----------------------------------------------------------------------------------------------------------
// detect the compiler used
#if !defined(KAOS_VC) && !defined(KAOS_GNUC) && !defined(KAOS_MWERKS) && !defined(KAOS_BORLANDC)
	/* 
	Compiler Identification:
		KAOS_VC			= Visual C++
		KAOS_GNUC		= gcc
		KAOS_MWERKS		= Metrowerks CodeWarrior C++
		KAOS_BORLANDC	= Borland C++
	*/
#	if defined(_MSC_VER) && defined(__INTEL_COMPILER)
#		define KAOS_INTEL_CPP
//#		pragma message("Compiling using Intel C++")
#	endif

#	if defined(_MSC_VER) && !defined(__INTEL_COMPILER)
#		define KAOS_VC 
//#		pragma message("Compiling using Microsoft Visual C++")
#	endif

#	if (defined(__GNUC__) || defined(__GNUG__) || defined(__MINGW32__)) && !defined(__clang__)
#		define KAOS_GNUC
//#		pragma message("Compiling using GNU C++")

#	endif

#	ifdef __MWERKS__
#		define KAOS_MWERKS
//#		pragma message("Compiling using Metroworks C++")
#	endif

#	ifdef __BORLANDC__
#		define KAOS_BORLANDC
//#		pragma message("Compiling using Borland C++")
#	endif

#	ifdef __clang__
#		define KAOS_CLANG
//#		pragma message("Compiling using CLANG")

#	endif

#endif

#if !defined(KAOS_INTEL_CPP) && !defined(KAOS_VC) && !defined(KAOS_GNUC) && !defined(KAOS_MWERKS) && !defined(KAOS_BORLANDC) && !defined(KAOS_CLANG)
#	error Es wurde kein Compiler definiert!
#endif




//-----------------------------------------------------------------------------------------------------------
#if defined(KAOS_INTEL_CPP)
#	define KAOS_COMPILER "ic"
#	define KAOS_COMPILER_STRING "Intel C++"
#	define KAOS_ASM __asm
#	define KAOS_ALIGN(val)	__declspec(align(val))
#	define KAOS_INLINECLASS
#	define KAOS_UNREFERENCED_PARAMETER(x) UNREFERENCED_PARAMETER(x)
#	define KAOS_INLINE
#	define KAOS_NORETURN __declspec(noreturn)

#	pragma warning (disable : 4996) // '...' was declared deprecated

#elif defined(KAOS_VC)
#	define KAOS_COMPILER "vc"
#	define KAOS_COMPILER_STRING "Microsoft Visual C++"
#	define KAOS_ASM __asm
#	define KAOS_ALIGN(val)	__declspec(align(val))
#	define KAOS_INLINECLASS
#	define KAOS_UNREFERENCED_PARAMETER(x) UNREFERENCED_PARAMETER(x)
#	define KAOS_INLINE __forceinline
#	define KAOS_NORETURN __declspec(noreturn)

#	if (_MSC_VER < 1310)	
#		error MSVC 7.1 are no longer supported due to standard compatibility

#	elif (_MSC_VER == 1400)
#		define KAOS_VC1400
#		undef KAOS_COMPILER_STRING
#		define KAOS_COMPILER_STRING "Microsoft Visual C++ 8 (vc1400)"

#	elif (_MSC_VER == 1500)
#		define KAOS_VC1500
#		undef KAOS_COMPILER_STRING
#		define KAOS_COMPILER_STRING "Microsoft Visual C++ 9 (vc1500)"

#	elif (_MSC_VER == 1600)
#		define KAOS_VC1600
#		undef KAOS_COMPILER_STRING
#		define KAOS_COMPILER_STRING "Microsoft Visual C++ 10 (vc1600)"

#	elif (_MSC_VER == 1700)
#		define KAOS_VC1700
#		undef KAOS_COMPILER_STRING
#		define KAOS_COMPILER_STRING "Microsoft Visual C++ 11 (vc1700)"

#	elif (_MSC_VER == 1800)
#		define KAOS_VC1800
#		undef KAOS_COMPILER_STRING
#		define KAOS_COMPILER_STRING "Microsoft Visual C++ 12 (vc1800)"

#	elif (_MSC_VER == 1900)
#		define KAOS_VC1900
#		define KAOS_VC19XX
#		undef KAOS_COMPILER_STRING
#		define KAOS_COMPILER_STRING "Microsoft Visual C++ 14 (vc1900)"

#	elif (_MSC_VER == 1910)
#		define KAOS_VC1910
#		define KAOS_VC19XX
#		undef KAOS_COMPILER_STRING
#		define KAOS_COMPILER_STRING "Microsoft Visual C++ 14.1 (vc1910)"

#	elif (_MSC_VER == 1911)
#		define KAOS_VC1911
#		define KAOS_VC19XX
#		undef KAOS_COMPILER_STRING
#		define KAOS_COMPILER_STRING "Microsoft Visual C++ 14.11 (vc1911)"

#	elif (_MSC_VER == 1912)
#		define KAOS_VC1912
#		define KAOS_VC19XX
#		undef KAOS_COMPILER_STRING
#		define KAOS_COMPILER_STRING "Microsoft Visual C++ 14.12 (vc1912)"

#	elif (_MSC_VER == 1913)
#		define KAOS_VC1913
#		define KAOS_VC19XX
#		undef KAOS_COMPILER_STRING
#		define KAOS_COMPILER_STRING "Microsoft Visual C++ 14.13 (vc1913)"

#	elif (_MSC_VER == 1914)
#		define KAOS_VC1914
#		define KAOS_VC19XX
#		undef KAOS_COMPILER_STRING
#		define KAOS_COMPILER_STRING "Microsoft Visual C++ 14.14 (vc1914)"

#	elif (_MSC_VER == 1915)
#		define KAOS_VC1915
#		define KAOS_VC19XX
#		undef KAOS_COMPILER_STRING
#		define KAOS_COMPILER_STRING "Microsoft Visual C++ 14.15 (vc1915)"

#	elif (_MSC_VER == 1916)
#		define KAOS_VC1916
#		define KAOS_VC19XX
#		undef KAOS_COMPILER_STRING
#		define KAOS_COMPILER_STRING "Microsoft Visual C++ 14.16 (vc1916)"

#	endif

#	pragma warning (disable : 4251)	// class XX needs DLL interface to be used...
#	pragma warning (disable : 4275)	// non dll-interface class used as base for dll-interface class
#	pragma warning (disable : 4355)	// 'this' : used in base member initializer list
#	pragma warning (disable : 4503)	// '...' : Die Laenge des ergaenzten Namens wurde ueberschritten. Der Name wurde gekuerzt.
#	pragma warning (disable : 4786)	// Symbol truncated to 255 characters
#	pragma warning (disable : 4996) // '...' was declared deprecated
#	pragma inline_depth(255)		// wenn wir inline coden soll es inline sein

//-----------------------------------------------------------------------------------------------------------
#elif defined(KAOS_GNUC)
#	define KAOS_COMPILER "gcc"
#	define KAOS_COMPILER_STRING "gcc"
#	define KAOS_ASM asm
#	define KAOS_ALIGN(val) __attribute__((aligned(val)))
#	define KAOS_INLINECLASS
#	define KAOS_UNREFERENCED_PARAMETER(x) (void)(x)
#	define KAOS_INLINE
#	define KAOS_NORETURN __attribute__((noreturn))

//-----------------------------------------------------------------------------------------------------------
#elif defined(KAOS_CLANG)
#	define KAOS_COMPILER "clang"
#	define KAOS_COMPILER_STRING "clang"
#	define KAOS_ASM asm
#	define KAOS_ALIGN(val) __attribute__((aligned(val)))
#	define KAOS_INLINECLASS
#	define KAOS_UNREFERENCED_PARAMETER(x) (void)(x)
#	define KAOS_INLINE
#	define KAOS_NORETURN __attribute__((noreturn))

//-----------------------------------------------------------------------------------------------------------
#elif defined(KAOS_MWERKS)
#	define	KAOS_COMPILER "mw"
#	define KAOS_COMPILER_STRING "Metrowerks CodeWarrior C++"
#	define KAOS_ASM asm
#	define KAOS_ALIGN(val)
#	define KAOS_INLINECLASS
#	define KAOS_UNREFERENCED_PARAMETER(x)
#	define KAOS_INLINE
#	define KAOS_NORETURN __attribute__((noreturn))

//-----------------------------------------------------------------------------------------------------------
#elif defined(KAOS_BORLANDC)
#	define KAOS_COMPILER "bcpp"
#	define KAOS_COMPILER_STRING "Borland C++"
#	define KAOS_ASM asm
#	define KAOS_ALIGN(val)
#	define KAOS_INLINECLASS
#	define KAOS_UNREFERENCED_PARAMETER(x)
#	define KAOS_INLINE
#	define KAOS_NORETURN

//-----------------------------------------------------------------------------------------------------------
#else
#	define KAOS_COMPILER_STRING "unknown_compiler"
#	error Unable to recognize compiler

#endif 

#endif // KKERNEL_SYSTEM_CONFIGURATION_COMPILER_COMPILER_H
