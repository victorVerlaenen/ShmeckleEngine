#pragma once

#ifdef SM_PLATFORM_WINDOWS

extern shmeckle::Application* shmeckle::CreateApplication();

int main(int argc, char** argv)
{
	auto application = shmeckle::CreateApplication();
	application->Run();
	delete application;
}

#endif