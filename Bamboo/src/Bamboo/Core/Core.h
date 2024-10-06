#pragma once

namespace Bamboo {
	//void InitializeCore();

	//void ShutdownCore();
}

// ∫Í∂®“Â
#ifdef  BAMBOO_BUILD_DLL
#define BAMBOO_API __declspec(dllexport)
#else
#define BAMBOO_API __declspec(dllimport)
#endif //  BAMBOO_BUILD_DLL
