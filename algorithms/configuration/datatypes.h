//-----------------------------------------------------------------------------------------------------------
/*!	\file kaos/kernel/system/configuration/datatypes/datatypes.h
	\brief Sämtliche Typendefinitionen
	\version 0.1
	\date 7.11.2002
	\author Christian Oberholzer

	Enthält sämtliche Typendefinitionen

	Die Typdefintionen werden in zwei Stufen eingebunden. Zuerst werden nur die Typedefinitions verwendet,
	damit die Common Types eingebunden werden können. In einer zweiten
	Stufe werden die TypeTraits und die Conversion-Templates eingebunden.
*/
//-----------------------------------------------------------------------------------------------------------
#ifndef KKERNEL_SYSTEM_CONFIGURATION_DATATYPES_DATATYPES_H
#define KKERNEL_SYSTEM_CONFIGURATION_DATATYPES_DATATYPES_H

#include "processor.h"
#include "compiler.h"

#if defined(KAOS_INTEL_CPP) || defined(KAOS_VC1400) || defined(KAOS_VC1500) || defined(KAOS_VC1600) || defined(KAOS_VC1700) || defined(KAOS_VC1800) || defined(KAOS_VC19XX)
#	include <intrin.h>
#endif

namespace kaos {

//-----------------------------------------------------------------------------------------------------------
#if defined(KAOS_INTEL_CPP) || defined(KAOS_VC1400) || defined(KAOS_VC1500) || defined(KAOS_VC1600) || defined(KAOS_VC1700) || defined(KAOS_VC1800) || defined(KAOS_VC19XX)
	typedef bool				bool_t;
	typedef char				char_t;
	typedef signed char			byte_t;			// 8 Bit
	typedef unsigned char		ubyte_t;		// 8 Bit
	typedef signed short int	word_t;			// 16 Bit
	typedef unsigned short int	uword_t;		// 16 Bit
	typedef signed int			dword_t;		// 32 Bit
	typedef unsigned int		udword_t;		// 32 Bit
	typedef signed __int64		qword_t;		// 64 Bit
	typedef unsigned __int64	uqword_t;		// 64 Bit
	typedef float				float32_t;		// 32 Bit
	typedef double				float64_t;		// 64 Bit
	typedef signed short int	short_t;		// halbe Registergrösse
	typedef unsigned short int	ushort_t;		// halbe Registergrösse
	typedef signed int			int_t;			// Registergrösse
	typedef unsigned int		uint_t;			// Registergrösse
	typedef signed __int64		long_t;			// Doppelte Registergrösse
	typedef unsigned __int64	ulong_t;		// Doppelte Registergrösse
	typedef float				float_t;		// Registergrösse
	typedef double				double_t;		// Doppelte Registergrösse
	typedef long double			long_double_t;	// Vierfache Registergrösse
	typedef signed __int64		signed_long_long_int_t;
	typedef unsigned __int64	unsigned_long_long_int_t;

	inline short interlocked_increment(short* const value)
	{ return _InterlockedIncrement16(value); }
	inline short interlocked_decrement(short* const value)
	{ return _InterlockedDecrement16(value); }
	inline long interlocked_increment(long* const value)
	{ return _InterlockedIncrement(value); }
	inline long interlocked_decrement(long* const value)
	{ return _InterlockedDecrement(value); }
	//inline long interlocked_increment(signed __int64* const value)
	//{ return _InterlockedIncrement64(value); }
	//inline long interlocked_decrement(signed __int64* const value)
	//{ return _InterlockedIncrement64(value); }
	inline short interlocked_compare_exchange(short* const destination, const short new_value, const short comparand)
	{ return _InterlockedCompareExchange16(destination, new_value, comparand); }
	inline long interlocked_compare_exchange(long* const destination, const long new_value, const long comparand)
	{ return _InterlockedCompareExchange(destination, new_value, comparand); }

//-----------------------------------------------------------------------------------------------------------
#elif defined(KAOS_GNUC) && defined(KAOS_CPU_X86)
	typedef bool					bool_t;
	typedef char					char_t;
	typedef signed char				byte_t;			// 8 Bit
	typedef unsigned char			ubyte_t;		// 8 Bit
	typedef signed short int		word_t;			// 16 Bit
	typedef unsigned short int		uword_t;		// 16 Bit
	typedef signed int				dword_t;		// 32 Bit
	typedef unsigned int			udword_t;		// 32 Bit
	typedef signed long long int	qword_t;		// 64 Bit
	typedef unsigned long long int	uqword_t;		// 64 Bit
	typedef float					float32_t;		// 32 Bit
	typedef double					float64_t;		// 64 Bit
	typedef signed short int		short_t;		// halbe Registergr?sse
	typedef unsigned short 			ushort_t;		// halbe Registergr?sse
	typedef signed int				int_t;			// Registergr?sse
	typedef unsigned int			uint_t;			// Registergr?sse
	typedef signed long long int	long_t;			// Doppelte Registergr?sse
	typedef unsigned long long int	ulong_t;		// Doppelte Registergr?sse
	typedef float					float_t;		// Registergr?sse
	typedef double					double_t;		// Doppelte Registergr?sse
	typedef long double				long_double_t;	// Vierfache Registergrösse
	typedef signed long long int	signed_long_long_int_t;
	typedef unsigned long long int	unsigned_long_long_int_t;

	// I guess that we have to use the functions described here:
	// http://gcc.gnu.org/onlinedocs/gcc-4.1.2/gcc/Atomic-Builtins.html#Atomic-Builtins
	// but only gcc version 4 supports those!
	inline short interlocked_increment(short* const value)
	{ return __sync_fetch_and_add(value, 1); }
	inline short interlocked_decrement(short* const value)
	{ return __sync_fetch_and_sub(value, 1); }
	inline long interlocked_increment(long* const value)
	{ return __sync_fetch_and_add(value, 1); }
	inline long interlocked_decrement(long* const value)
	{ return __sync_fetch_and_sub(value, 1); }
	//inline long interlocked_increment(signed long long int* const value)
	//{ return __sync_fetch_and_add(value, 1); }
	//inline long interlocked_decrement(signed long long int* const value)
	//{ return __sync_fetch_and_sub(value, 1); }
	inline short interlocked_compare_exchange(short* const destination, const short new_value, const short comparand)
	{ return __sync_val_compare_and_swap(destination, comparand, new_value); }
	inline long interlocked_compare_exchange(long* const destination, const long new_value, const long comparand)
	{ return __sync_val_compare_and_swap(destination, comparand, new_value); }

//-----------------------------------------------------------------------------------------------------------
#elif defined(KAOS_GNUC) && defined(KAOS_CPU_X64)
	typedef bool					bool_t;
	typedef char					char_t;
	typedef signed char				byte_t;			// 8 Bit
	typedef unsigned char			ubyte_t;		// 8 Bit
	typedef signed short int		word_t;			// 16 Bit
	typedef unsigned short int		uword_t;		// 16 Bit
	typedef signed int				dword_t;		// 32 Bit
	typedef unsigned int			udword_t;		// 32 Bit
	typedef signed long long int	qword_t;		// 64 Bit
	typedef unsigned long long int	uqword_t;		// 64 Bit
	typedef float					float32_t;		// 32 Bit
	typedef double					float64_t;		// 64 Bit
	typedef signed short int		short_t;		// halbe Registergr?sse
	typedef unsigned short			ushort_t;		// halbe Registergr?sse
	typedef signed int				int_t;			// Registergr?sse
	typedef unsigned int			uint_t;			// Registergr?sse
	typedef signed long long int	long_t;			// Doppelte Registergr?sse
	typedef unsigned long long int	ulong_t;		// Doppelte Registergr?sse
	typedef float					float_t;		// Registergr?sse
	typedef double					double_t;		// Doppelte Registergr?sse
	typedef long double				long_double_t;	// Vierfache Registergrösse
	typedef signed long long int	signed_long_long_int_t;

	// I guess that we have to use the functions described here:
	// http://gcc.gnu.org/onlinedocs/gcc-4.1.2/gcc/Atomic-Builtins.html#Atomic-Builtins
	// but only gcc version 4 supports those!
	inline short interlocked_increment(short* const value)
	{ return __sync_fetch_and_add(value, 1); }
	inline short interlocked_decrement(short* const value)
	{ return __sync_fetch_and_sub(value, 1); }
	inline long interlocked_increment(long* const value)
	{ return __sync_fetch_and_add(value, 1); }
	inline long interlocked_decrement(long* const value)
	{ return __sync_fetch_and_sub(value, 1); }
	//inline long interlocked_increment(signed long long int* const value)
	//{ return __sync_fetch_and_add(value, 1); }
	//inline long interlocked_decrement(signed long long int* const value)
	//{ return __sync_fetch_and_sub(value, 1); }
	inline short interlocked_compare_exchange(short* const destination, const short new_value, const short comparand)
	{ return __sync_val_compare_and_swap(destination, comparand, new_value); }
	inline long interlocked_compare_exchange(long* const destination, const long new_value, const long comparand)
	{ return __sync_val_compare_and_swap(destination, comparand, new_value); }
	typedef unsigned long long int  unsigned_long_long_int_t;

//-----------------------------------------------------------------------------------------------------------
#elif defined(KAOS_CLANG)
	typedef bool					bool_t;
	typedef char					char_t;
	typedef signed char				byte_t;			// 8 Bit
	typedef unsigned char			ubyte_t;		// 8 Bit
	typedef signed short int		word_t;			// 16 Bit
	typedef unsigned short int		uword_t;		// 16 Bit
	typedef signed int				dword_t;		// 32 Bit
	typedef unsigned int			udword_t;		// 32 Bit
	typedef signed long long int	qword_t;		// 64 Bit
	typedef unsigned long long int	uqword_t;		// 64 Bit
	typedef float					float32_t;		// 32 Bit
	typedef double					float64_t;		// 64 Bit
	typedef signed short int		short_t;		// halbe Registergr?sse
	typedef unsigned short			ushort_t;		// halbe Registergr?sse
	typedef signed int				int_t;			// Registergr?sse
	typedef unsigned int			uint_t;			// Registergr?sse
	typedef __int64_t				long_t;			// Doppelte Registergr?sse
	typedef __uint64_t				ulong_t;		// Doppelte Registergr?sse
	typedef float					float_t;		// Registergr?sse
	typedef double					double_t;		// Doppelte Registergr?sse
	typedef long double				long_double_t;	// Vierfache Registergrösse
	typedef signed long long int	signed_long_long_int_t;

	// I guess that we have to use the functions described here:
	// http://gcc.gnu.org/onlinedocs/gcc-4.1.2/gcc/Atomic-Builtins.html#Atomic-Builtins
	// but only gcc version 4 supports those!
	inline short interlocked_increment(short* const value)
	{ return __sync_fetch_and_add(value, 1); }
	inline short interlocked_decrement(short* const value)
	{ return __sync_fetch_and_sub(value, 1); }
	inline long interlocked_increment(long* const value)
	{ return __sync_fetch_and_add(value, 1); }
	inline long interlocked_decrement(long* const value)
	{ return __sync_fetch_and_sub(value, 1); }
	//inline long interlocked_increment(signed long long int* const value)
	//{ return __sync_fetch_and_add(value, 1); }
	//inline long interlocked_decrement(signed long long int* const value)
	//{ return __sync_fetch_and_sub(value, 1); }
	inline short interlocked_compare_exchange(short* const destination, const short new_value, const short comparand)
	{ return __sync_val_compare_and_swap(destination, comparand, new_value); }
	inline long interlocked_compare_exchange(long* const destination, const long new_value, const long comparand)
	{ return __sync_val_compare_and_swap(destination, comparand, new_value); }
	typedef unsigned long long int  unsigned_long_long_int_t;

//-----------------------------------------------------------------------------------------------------------
#else
#	error DataTypes: Kein Compiler definiert

#endif

//-----------------------------------------------------------------------------------------------------------
class NonCopyable
{
protected:
	inline NonCopyable(){}
	inline ~NonCopyable(){}
private:
	NonCopyable(const NonCopyable&);
	const NonCopyable& operator = (const NonCopyable&);
};

} // namespace kaos

#endif // KKERNEL_SYSTEM_CONFIGURATION_DATATYPES_DATATYPES_H
