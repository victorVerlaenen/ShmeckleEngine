#include "Shmeckle.h"

class SandboxApplication : public Shmeckle::Application
{
public:
	SandboxApplication()
	{

	}

	~SandboxApplication()
	{

	}
};

Shmeckle::Application* Shmeckle::CreateApplication()
{
	return new SandboxApplication();
}