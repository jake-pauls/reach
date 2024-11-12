#pragma once

#include <filesystem>
#include <iomanip>
#include <iostream>

#ifdef RDEBUG
	#ifdef WIN32
		#define DEBUGBREAK() __debugbreak()
	#else
		#include <signal.h>
		#define DEBUGBREAK() raise(SIGTRAP)
	#endif
#else
	#define DEBUGBREAK()
#endif

#ifdef RDEBUG
	#ifdef WIN32
		#include <assert.h>
	#else
		#include <cassert>
	#endif
#endif

#ifdef RDEBUG
	#define __FILE_NAME__ std::filesystem::path(__FILE__).filename().string()
	#define __FILE_NAME_C_STR__ std::filesystem::path(__FILE__).filename().string().c_str()

	#ifdef WIN32
		// TODO: find an alternate method with soft buffer maximum
		#define __VS_PRINT__(fmt, ...) \
				{ \
					char str[256]; \
					sprintf_s(str, sizeof(str), fmt, __VA_ARGS__); \
					OutputDebugStringA(str); \
				} \

		#define __PRINT__(fmt, ...) fprintf(stdout, fmt, __VA_ARGS__); __VS_PRINT__(fmt, __VA_ARGS__)
	#else
		#define __PRINT__(fmt, ...) fprintf(stdout, fmt, __VA_ARGS__); 
	#endif

	#define __LOG__(level, message, ...) __PRINT__("[%s] " ## message ## "\n", level, ## __VA_ARGS__)

	#define RLOG(message, ...) __LOG__("debug", message, __VA_ARGS__)
	#define RWARN(message, ...) __LOG__("warn", message, __VA_ARGS__)
	#define RERROR(message, ...) __LOG__("error", message, __VA_ARGS__)
#else
	#define RLOG(message, ...) 
	#define RWARN(message, ...)
	#define RERROR(message, ...)
#endif

#ifdef RDEBUG
	/// @brief Wrapper for a generic platform assert.
	#define RASSERT(check) assert((check))

	/// @brief Evaluates the provided check and logs the provided message if an assert is going to be thrown.
	#define RVERIFY(check, message) \
		{ \
			if (!!(check)) \
			{ \
				RERROR(message); \
				RASSERT(false); \
			} \
		} \

#else
	#define RASSERT(check)
	#define RVERIFY(check, message)
#endif
