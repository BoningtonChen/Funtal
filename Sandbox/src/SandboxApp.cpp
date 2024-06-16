#include <cstdint>
#include <Funtal.h>

class Sandbox : public Funtal::Application
{
public:
	Sandbox()
	{
		
	}

	~Sandbox()
	{
		
	}
};

Funtal::Application* Funtal::CreateApplication()
{
	return new Sandbox();
}