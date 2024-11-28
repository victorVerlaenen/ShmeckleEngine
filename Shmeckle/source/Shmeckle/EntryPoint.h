#pragma once

#ifdef SHMECKLE_PLATFORM_WINDOWS

extern shmeckle::Application* shmeckle::CreateApplication();

int main(int argc, char** argv)
{
	shmeckle::Logger::Initialize();
	shmeckle::Logger::CoreInfo("Logger initialized.");

	auto application = shmeckle::CreateApplication();
	application->Run();
	delete application;
}

#endif