#pragma once

#ifdef SM_PLATFORM_WINDOWS

// This will be defined somewhere in a client application
extern Shmeckle::Application* Shmeckle::CreateApplication();

int main(int argc, char** argv)
{
	auto pApp = Shmeckle::CreateApplication();
	pApp->Run();

	delete pApp;
}

#endif