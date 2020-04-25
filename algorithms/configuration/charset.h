//-----------------------------------------------------------------------------------------------------------
/*!	\file kaos/kernel/system/configuration/charset/charset.h
	\brief Definiert Makros f�r die verschiedenen m�glichen Zeichens�tze
	\version 0.1
	\date 3.11.2003
	\author Christian Oberholzer

	Definiert Makros f�r die verschiedenen m�glichen Zeichens�tze
*/
//-----------------------------------------------------------------------------------------------------------
#ifndef KKERNEL_SYSTEM_CONFIGURATION_CHARSET_CHARSET_H
#define KKERNEL_SYSTEM_CONFIGURATION_CHARSET_CHARSET_H

#if defined(KAOS_VC)
#pragma warning(push)
#pragma warning(disable:4365)
#endif

#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>

#if defined(KAOS_VC)
#pragma warning(pop)
#endif

namespace kaos {

//-----------------------------------------------------------------------------------------------------------
template <
	typename CharT
>
struct CharTraits
{
	enum 
	{
		SIZE = sizeof(CharT)
	};

	static CharT* strcpy(CharT* dest, const CharT* source);
	static CharT* strcat(CharT* dest, const CharT* source);
	static size_t strlen(const CharT* string);
	static CharT* strchr(CharT* string, CharT c);
	static const CharT* strchr(const CharT* string, CharT c);
	static CharT* strrchr(CharT* string, CharT c);
	static const CharT* strrchr(const CharT* string, CharT c);
	static int strcmp(const CharT* lhs, const char* rhs);
	static CharT toupper(const CharT c);
	static CharT tolower(const CharT c);
	static bool is_alphabetic(CharT c);
	static bool is_numeric(CharT c);
	static bool is_alphanum(CharT c);
	static bool is_lower(CharT c);
	static bool is_upper(CharT c);
	static bool is_space(CharT c);
	static bool is_newline(CharT c);
	static bool is_tab(CharT c);
	static bool is_whitespace(CharT c);
	static bool is_printable(CharT c);
};




template <>
struct CharTraits<char>
{
	inline static char* strcpy(char* dest, const char* source)
	{
		return ::strcpy(dest, source);
	}
	inline static char* strcat(char* dest, const char* source)
	{
		return ::strcat(dest, source);
	}
	inline static size_t strlen(const char* string)
	{
		return ::strlen(string);
	}
	inline static char* strchr(char* string, char c)
	{
		return ::strchr(string, c);
	}
	inline static const char* strchr(const char* string, char c)
	{
		return ::strchr(string, c);
	}
	inline static char* strrchr(char* string, char c)
	{
		return ::strrchr(string, c);
	}
	inline static const char* strrchr(const char* string, char c)
	{
		return ::strrchr(string, c);
	}
	inline static int strcmp(const char* lhs, const char* rhs)
	{
		return ::strcmp(lhs, rhs);
	}
	inline static char toupper(char c)
	{
		return (char)::toupper(c);
	}
	inline static char tolower(char c)
	{
		return (char)::tolower(c);
	}
	inline static bool is_alphabetic(char c)
	{
		return (::isalpha((unsigned char)c) ? true : false);
	}
	inline static bool is_numeric(char c)
	{
		return (::isdigit((unsigned char)c) ? true : false);
	}
	inline static bool is_alphanum(char c)
	{
		return (::isalnum((unsigned char)c) ? true : false);
	}
	inline static bool is_lower(char c)
	{
		return (::islower((unsigned char)c) ? true : false);
	}
	inline static bool is_upper(char c)
	{
		return (::isupper((unsigned char)c) ? true : false);
	}
	inline static bool is_space(char c)
	{
		return (c == ' ');
	}
	inline static bool is_newline(char c)
	{
		return (c == '\n');
	}
	inline static bool is_tab(char c)
	{
		return (c == '	');
	}
	inline static bool is_whitespace(char c)
	{
		return (::isspace((unsigned char)c) ? true : false);
	}
	inline static bool is_printable(char c)
	{
		return (::isprint((unsigned char)c) ? true : false);
	}
};




//-----------------------------------------------------------------------------------------------------------
template <>
struct CharTraits<wchar_t>
{
	inline static wchar_t* strcpy(wchar_t* dest, const wchar_t* source)
	{
		return wcscpy(dest, source);
	}
	inline static wchar_t* strcat(wchar_t* dest, const wchar_t* source)
	{
		return wcscat(dest, source);
	}
	inline static size_t strlen(const wchar_t* string)
	{
		return wcslen(string);
	}
	inline static wchar_t* strchr(wchar_t* string, wchar_t c)
	{
		return ::wcschr(string, c);
	}
	inline static const wchar_t* strchr(const wchar_t* string, wchar_t c)
	{
		return ::wcschr(string, c);
	}
	inline static wchar_t* strrchr(wchar_t* string, wchar_t c)
	{
		return ::wcsrchr(string, c);
	}
	inline static const wchar_t* strrchr(const wchar_t* string, wchar_t c)
	{
		return ::wcsrchr(string, c);
	}
	inline static int strcmp(const wchar_t* lhs, const wchar_t* rhs)
	{
		return ::wcscmp(lhs, rhs);
	}
	inline static wchar_t toupper(wchar_t c)
	{
		return ::towupper(c);
	}
	inline static wchar_t tolower(wchar_t c)
	{
		return ::towlower(c);
	}
	inline static bool is_alphabetic(wchar_t c)
	{
		return (::iswalpha(c) ? true : false);
	}
	inline static bool is_numeric(wchar_t c)
	{
		return (::iswdigit(c) ? true : false);
	}
	inline static bool is_alphanum(wchar_t c)
	{
		return (::iswalnum(c) ? true : false);
	}
	inline static bool is_lower(wchar_t c)
	{
		return (::iswlower(c) ? true : false);
	}
	inline static bool is_upper(wchar_t c)
	{
		return (::iswupper(c) ? true : false);
	}
	inline static bool is_space(wchar_t c)
	{
		return (c == L' ');
	}
	inline static bool is_newline(wchar_t c)
	{
		return (c == L'\n');
	}
	inline static bool is_tab(wchar_t c)
	{
		return (c == L'	');
	}
	inline static bool is_whitespace(wchar_t c)
	{
		return (::iswspace(c) ? true : false);
	}
	inline static bool is_printable(wchar_t c)
	{
		return (::iswprint(c) ? true : false);
	}
};

} // namespace kaos




//-----------------------------------------------------------------------------------------------------------
/*
 *	Konvertierungen zwischen den einzelnen Formaten
 */
namespace kaos {

/*
 *	Todo, For windows use 'MultiByteToWideChar' and 'WideCharToMultiByte'
 */

} // namespace kaos

#endif // KKERNEL_SYSTEM_CONFIGURATION_CHARSET_CHARSET_H
