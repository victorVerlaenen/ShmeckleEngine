#pragma once

#ifdef SM_PLATFORM_WINDOWS

extern shmeckle::Application* shmeckle::CreateApplication();

int main(int argc, char** argv)
{
	shmeckle::Logger::Initialize();

	shmeckle::Logger::CoreTrace("Trace");
	shmeckle::Logger::CoreInfo("Info");
	shmeckle::Logger::Warning("Warning");
	shmeckle::Logger::Error("Error");
	shmeckle::Logger::Critical("Critical");

	auto application = shmeckle::CreateApplication();
	application->Run();
	delete application;
}

#endif