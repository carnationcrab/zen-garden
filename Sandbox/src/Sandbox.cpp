#include <ZenGarden.h>

class Sandbox : public ZenGarden::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

ZenGarden::Application* ZenGarden::CreateApplication() 
{
	return new Sandbox();
}