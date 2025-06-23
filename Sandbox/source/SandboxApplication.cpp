#include "Shmeckle.h"

class SandboxApplication : public Shmeckle::Application
{
public:
	SandboxApplication() noexcept
	{
		Shmeckle::Logger::Info("Sandbox is being created...");
	}

	~SandboxApplication()
	{

	}

};

std::unique_ptr<Shmeckle::Application> Shmeckle::CreateApplication()
{
	return std::make_unique<SandboxApplication>();
}