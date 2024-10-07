#include "Core.h"
#include "Log.h"
#include <Windows.h>

#define BAMBOO_BUILD_ID "v0.1a"

namespace Bamboo {
	void InitializeCore()
	{
		Bamboo::Log::Init();

		BB_CORE_TRACE("Bamboo Engine {}", BAMBOO_BUILD_ID);
		BB_CORE_TRACE("Initializing...");
	}

	void ShutdownCore()
	{
		BB_CORE_TRACE("Shutting down...");
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Bamboo::InitializeCore();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		Bamboo::ShutdownCore();
		break;
	}

	return TRUE;
}
