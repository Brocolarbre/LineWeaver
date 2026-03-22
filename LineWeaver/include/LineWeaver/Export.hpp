#pragma once

#ifdef _WIN32
	#ifdef LINEWEAVER_STATIC
		#define LINEWEAVER_EXPORT
	#else
		#ifdef LINEWEAVER_EXPORT
			#define LINEWEAVER_EXPORT __declspec(dllexport)
		#else
			#define LINEWEAVER_EXPORT __declspec(dllimport)
		#endif
	#endif
#elif __linux__
	#define LINEWEAVER_EXPORT
#endif