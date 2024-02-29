#pragma once

#ifdef ZG_PLATFORM_WINDOWS
	#ifdef ZG_BUILD_DLL
		#define ZENGARDEN_API __declspec(dllexport)
	#else
		#define ZENGARDEN_API __declspec(dllimport)
	#endif
#else
	#error ERROR: Unsupported Platform (Core.h)
#endif