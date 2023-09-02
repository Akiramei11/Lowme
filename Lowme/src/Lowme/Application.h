#pragma once

#include "Core.h"

namespace Lowme {

	class LOWME_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}
