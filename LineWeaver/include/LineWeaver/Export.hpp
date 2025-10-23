#pragma once

#ifdef _WIN32
	#ifdef LINEWEAVER_STATIC
		#define LINEWEAVER_API
	#else
		#ifdef LINEWEAVER_EXPORT
			#define LINEWEAVER_API __declspec(dllexport)
		#else
			#define LINEWEAVER_API __declspec(dllimport)
		#endif
	#endif
#elif __linux__
	#define LINEWEAVER_API
#endif