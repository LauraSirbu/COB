//-----------------------------------------------------------------------------------------------------------
/*!	\file kaos/kernel/system/debugging/assert.cpp
	\brief Implementiert kaos::assertfunction
	\version 0.1
	\date 3.11.2003
	\author Christian Oberholzer

	Implementiert kaos::assertfunction
*/
//-----------------------------------------------------------------------------------------------------------
#include "../configuration/configuration.h"
#include <assert.h>

namespace kaos {

//-----------------------------------------------------------------------------------------------------------
bool assertfunction(
	bool expression_result, 
	const char* assert_file, 
	const long assert_line, 
	const char* assert_expression, 
	const char* assert_description, 
	bool* const ignore_always
)
{
	KAOS_UNREFERENCED_PARAMETER(assert_line);
	KAOS_UNREFERENCED_PARAMETER(ignore_always);

	if (!expression_result)
	{
		bool result;

		//LOG_WRITE_L1(LOGSEVERITY_ERROR, "kaos.kernel", "kaos::assertfunction", "ASSERT in '", assert_file_string, ": ", assert_line, "Expression: '", assert_expression_string, "' Errordescription: '", assert_description_string, "'");
		assert(false);

		//__debugbreak();
		result = false;

		return result;
	}
	
	return true;
}

} // namespace kaos
