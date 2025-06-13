# Shmeckle Engine
Shmeckle Engine is a lightweight game engine project aimed at learning and implementing key principles of engine development. It currently supports x64 architectures and windows.
## Setup
### 1. Clone the repository
### 2. Add a new project and set is as startup
### 3. Build the engine and link your client application to the engines dll
### 4. For now you will have to copy the dll into the client's executable folder

## Making your own application
### 1. Include "Shmeckle.h" 
### 2. Inherit from **Shmeckle::Application**
### 3. Implement the entrypoint factory
In your application (for example: **SandboxApplication.cpp**)
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
The **CreateApplication()** function will be called by the engine via an ```extern``` declaration to start your application.

