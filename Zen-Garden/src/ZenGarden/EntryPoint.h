#pragma once

#ifdef ZG_PLATFORM_WINDOWS

extern ZenGarden::Application* ZenGarden::CreateApplication();

int main(int argc, char** argv)
{
	ZenGarden::Application* app = ZenGarden::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif