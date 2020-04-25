//-----------------------------------------------------------------------------------------------------------
/*!	\file kaos/kernel/system/debugging/assert.h
	\brief Definiert kaos_assert
	\version 0.1
	\date 3.11.2003
	\author Christian Oberholzer

	Definiert kaos_assert
*/
//-----------------------------------------------------------------------------------------------------------
#ifndef KAOS_TYPES_DEBUGGING_ASSERT_H
#define KAOS_TYPES_DEBUGGING_ASSERT_H

#if defined(KAOS_USE_ASSERTS) && defined(KAOS_VC)
#	define kaos_assert(expression, description)											\
		if (!(expression))																\
		{																				\
			static bool ignore_always_flag = false;										\
			if (!ignore_always_flag)													\
			{																			\
				bool assert_value = false;												\
																						\
				if (!::kaos::assertfunction(assert_value,								\
									  __FILE__,											\
									  __LINE__,											\
									  #expression,										\
									  description,										\
									  &ignore_always_flag))								\
				{																		\
					__debugbreak(); /* same as KAOS_ASM { int 3 } */					\
				}																		\
			}																			\
		}
#else 
#	define kaos_assert(expression, description)
#endif

namespace kaos {

bool assertfunction(
	bool expression_result, 
	const char* assert_file, 
	const long assert_line, 
	const char* assert_expression, 
	const char* assert_description, 
	bool* const ignore_always
);

} // namespace kaos

#endif // KAOS_TYPES_DEBUGGING_ASSERT_H
