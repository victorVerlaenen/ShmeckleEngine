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

	SandboxApplication(const SandboxApplication& other) = delete;
	SandboxApplication(SandboxApplication&& other) = delete;
	SandboxApplication& operator=(const SandboxApplication& other) = delete;
	SandboxApplication& operator=(SandboxApplication&& other) = delete;
};

std::unique_ptr<Shmeckle::Application> Shmeckle::CreateApplication()
{
	return std::make_unique<SandboxApplication>();
}