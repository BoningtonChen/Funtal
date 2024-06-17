#include <cstdint>
#include <Funtal.h>

class Sandbox : public Funtal::Application
{
public:
	Sandbox() = default;

	~Sandbox() = default;
};

Funtal::Application* Funtal::CreateApplication()
{
	return new Sandbox();
}