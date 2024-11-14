#include <Shmeckle.h>

class Sandbox : public shmeckle::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

shmeckle::Application* shmeckle::CreateApplication()
{
	return new Sandbox();
}