//-----------------------------------------------------------------------------------------------------------
/*!	\file kaos/kernel/system/configuration/processor/processor.h
	\brief Prozessorenspezifische Flags setzen
	\version 0.1
	\date 6.2.2003
	\author Christian Oberholzer

	In dieser Datei werden Flags gesetzt welche die unterschiedlichen Prozessoren behandeln helfen.
*/
//-----------------------------------------------------------------------------------------------------------
#ifndef KKERNEL_SYSTEM_CONFIGURATION_PROCESSOR_PROCESSOR_H
#define KKERNEL_SYSTEM_CONFIGURATION_PROCESSOR_PROCESSOR_H

#if defined(KAOS_VC)
#	if defined(_M_ALPHA) && _M_ALPHA != 0
#		define KAOS_CPU "alpha"
#		define KAOS_CPU_ALPHA
#		define KAOS_LITTLEENDIAN
#	elif defined(_M_X64) && _M_X64 != 0
#		define KAOS_CPU "x64"
#		define KAOS_CPU_X64
#		define KAOS_LITTLEENDIAN
#	elif defined(_M_IX86) && _M_IX86 != 0
#		define KAOS_CPU "x86"
#		define KAOS_CPU_X86
#		define KAOS_LITTLEENDIAN
#	elif defined(_M_MPPC) && _M_MPPC != 0
#		define KAOS_CPU "ppc"
#		define KAOS_CPU_PPC
#		define KAOS_BIGENDIAN
#	elif defined(_M_MRX000) && _M_MRX000 != 0
#		define KAOS_CPU "mips"
#		define KAOS_CPU_MIPS
#		define KAOS_LITTLEENDIAN
#	else
#		define KAOS_CPU "other"
#		define KAOS_CPU_OTHER
#		define KAOS_LITTLEENDIAN
#	endif

#elif defined(KAOS_GNUC)
#	if defined(i386) || defined(__i386) || defined(__i386__)
#		define KAOS_CPU	"x86"
#		define KAOS_CPU_X86
#		define KAOS_LITTLEENDIAN
#	elif defined(__amd64) || defined(__amd64__)
#		define KAOS_CPU "x64"
#		define KAOS_CPU_X64
#		define KAOS_LITTLEENDIAN
#	elif alpha
#		define KAOS_CPU "alpha"
#		define KAOS_CPU_ALPHA
#		define KAOS_LITTLEENDIAN
#	elif m68k	
#		define KAOS_CPU "m68k"
#		define KAOS_CPU_M68K
#		define KAOS_BIGENDIAN
#	elif defined(__mips64)
#		define KAOS_CPU "mips 64"
#		define KAOS_CPU_X64
#		define KAOS_LITTLEENDIAN
#	elif defined(__mips__) && __mips == 32
#		define KAOS_CPU "mips 32"
#		define KAOS_CPU_X86
#		define KAOS_LITTLEENDIAN
#	elif ppc
#		define KAOS_CPU "ppc"
#		define KAOS_CPU_PPC
#		define KAOS_BIGENDIAN
#	elif sparc
#		define KAOS_CPU "sparc"
#		define KAOS_CPU_SPARC
#		define KAOS_LITTLEENDIAN
#	elif __aarch64__
		// TODO: VERIFY !!
#		define KAOS_CPU "aarch64"
#		define KAOS_CPU_X64
#		define KAOS_BIGENDIAN
#	elif __arm__
#		define KAOS_CPU "arm"
#		define KAOS_CPU_X86
#		define KAOS_BIGENDIAN
#	elif KAOS_WIN32
#		define KAOS_CPU "i386"
#		define KAOS_CPU_I386
#		define KAOS_LITTLEENDIAN
#	else
#		define KAOS_CPU "other"
#		define KAOS_CPU_OTHER
#		define KAOS_LITTLEENDIAN
#	endif
#elif defined(KAOS_CLANG)
#	if defined(__i386)
#		define KAOS_CPU_X86
#		define KAOS_CPU "x86"
#		define KAOS_LITTLEENDIAN
#	elif defined(__x86_64) || defined(__amd64)
#		define KAOS_CPU_X64
#		define KAOS_CPU "x64"
#		define KAOS_LITTLEENDIAN
#	elif defined(__arm__)
#		define KAOS_CPU_ARM
#		define KAOS_CPU "arm"
#		define KAOS_BIGENDIAN
#	elif defined(__aarch64__)
#		define KAOS_CPU_ARM64
#		define KAOS_CPU "arm64"
#		define KAOS_BIGENDIAN
#	else
#		error Clang target architecture not recognized
#	endif
#else
#	error Processor: Target processor recognized!
#	define KAOS_CPU "other"
#	define KAOS_LITTLEENDIAN
#endif

#endif // KKERNEL_SYSTEM_CONFIGURATION_PROCESSOR_PROCESSOR_H

