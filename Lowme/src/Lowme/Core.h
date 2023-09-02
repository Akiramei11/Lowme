#pragma once

#ifdef LM_PLATFORM_WINDOWS
	#ifdef LM_BUILD_DLL
		#define LOWME_API __declspec(dllexport)
	#else
		#define LOWME_API __declspec(dllimport)
	#endif
#else
#error Lowme only suports Windows!
#endif