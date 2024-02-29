#pragma once

#include <SDL.h>
#include <vector>
#include <string>

#include "Core.h"

#include "RenderWindow.h"
#include "Entity.h"
#include "Utils.h"
#include "Timestepper.h"

namespace ZenGarden
{
	class ZENGARDEN_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
	private:
		RenderWindow window;
		TimeStepper timeStepper;
		std::vector<Entity> entities;
		bool gameRunning;
	};

	// defined in client
	Application* CreateApplication();
}