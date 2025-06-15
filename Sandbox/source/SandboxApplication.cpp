#include "Shmeckle.h"

class SandboxApplication : public Shmeckle::Application
{
public:
	SandboxApplication()
	{
		std::unique_ptr<int> p {new int};
	}

	~SandboxApplication()
	{

	}
};

Shmeckle::Application* Shmeckle::CreateApplication()
{
	return new SandboxApplication();
}