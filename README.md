****!!! This project is discontinued for now !!!****
============================================

# Shmeckle Engine
Shmeckle Engine is a lightweight game engine project aimed at learning and implementing key principles of engine development. It currently supports x64 architectures and windows.
## Setup
**1. Clone the repository**<br>
**2. Add a new project and set is as startup**<br>
**3. Build the engine and link your client application to the engines dll**<br>
**4. Define ```SM_PLATFORM_WINDOWS``` in your application**<br>
**4. For now you will have to copy the dll into the client's executable folder**<br>

## Making your own application
**1. Include** ```"Shmeckle.h"```<br>
**2. Inherit from** ```Shmeckle::Application```<br>
**3. Implement the entrypoint factory**<br>
In your application (for example: ```SandboxApplication.cpp```)<br>
```
#include "Shmeckle.h"

class SandboxApplication : public Shmeckle::Application
{
public:
	SandboxApplication() { }
	~SandboxApplication() { }
};

Shmeckle::Application* Shmeckle::CreateApplication()
{
	return new SandboxApplication();
}
```
The ```CreateApplication()``` function will be called by the engine via an ```extern``` declaration to start your application.

