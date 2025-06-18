#include "Shmeckle.h"

class SandboxApplication : public Shmeckle::Application
{
public:
	SandboxApplication() noexcept
	{
		
	}

	~SandboxApplication()
	{

	}

};

std::unique_ptr<Shmeckle::Application> Shmeckle::CreateApplication()
{
	return std::make_unique<SandboxApplication>();
}