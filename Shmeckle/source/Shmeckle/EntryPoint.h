#pragma once

#ifdef SHM_PLATFORM_WINDOWS
#include <memory>

// This will be defined somewhere in a client application
extern std::unique_ptr<Shmeckle::Application> Shmeckle::CreateApplication();

int main(int /*argc*/, char** /*argv*/)
{
	auto upApp = Shmeckle::CreateApplication();
	if (upApp)
	{
		upApp->Run();
	}
}

#endif