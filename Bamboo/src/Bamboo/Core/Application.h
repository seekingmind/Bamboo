#pragma once

#include "Core.h"

namespace Bamboo {
	class BAMBOO_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();

	private:
	};

	// 由client来实现
	Application* CreateApplication();
}
