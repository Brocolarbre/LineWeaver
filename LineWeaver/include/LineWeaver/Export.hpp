#pragma once

#if defined(LINEWEAVER_STATIC)
	#define LINEWEAVER_API
#else
	#if defined(_WIN32)
		#if defined(LINEWEAVER_BUILD)
			#define LINEWEAVER_API __declspec(dllexport)
		#else
			#define LINEWEAVER_API __declspec(dllimport)
		#endif
	#else
		#define LINEWEAVER_API __attribute__((visibility("default")))
	#endif
#endif