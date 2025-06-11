# Shmeckle Engine
Shmeckle Engine is a lightweight game engine project aimed at learning and implementing key principles of engine development. It currently supports x64 architectures and leverages GLFW and OpenGL for rendering.

## build folder layout
```
├───build
│   └───x64-Debug
│       │   .ninja_deps
│       │   .ninja_log
│       │   build.ninja
│       │   CMakeCache.txt
│       │   cmake_install.cmake
│       │   VSInheritEnvironments.txt
│       │
│       ├───.cmake
│       │   └───api
│       │       └───v1
│       │           ├───query
│       │           │   └───client-MicrosoftVS
│       │           │           query.json
│       │           │
│       │           └───reply
│       │                   cache-v2-d86fc53a1fd8c7b37bc8.json
│       │                   cmakeFiles-v1-d8b2b5d55b96f77fd6fd.json
│       │                   codemodel-v2-0f9d1531cf33ca32c87f.json
│       │                   directory-.-Debug-d0094a50bb2071803777.json
│       │                   directory-Sandbox-Debug-5f4392a0e5eaed8a8ee6.json
│       │                   directory-Shmeckle-Debug-c2501652f675a1a6274d.json
│       │                   directory-Shmeckle.vendor.GLFW-Debug-8af4c00230c9bf5c382d.json
│       │                   directory-Shmeckle.vendor.GLFW.src-Debug-29776fe9d9b529ba7909.json
│       │                   index-2024-12-22T13-37-18-0066.json
│       │                   target-glfw-Debug-ba49296f64f57b1a59fe.json
│       │                   target-Sandbox-Debug-a4a621996afade41f3c9.json
│       │                   target-Shmeckle-Debug-c8307561ad8cc13649e2.json
│       │                   target-uninstall-Debug-63112bb6de43fe21b56a.json
│       │                   target-update_mappings-Debug-ec50b5e9e0620caaed4f.json
│       │                   toolchains-v1-d313881b9fb0958aa4fd.json
│       │
│       ├───bin
│       │   ├───Sandbox
│       │   │       Sandbox.exe
│       │   │       Sandbox.ilk
│       │   │       Sandbox.pdb
│       │   │       Shmeckle.dll
│       │   │
│       │   └───Shmeckle
│       │           Shmeckle.dll
│       │           Shmeckle.ilk
│       │           Shmeckle.pdb
│       │
│       ├───bin-int
│       │   │   glfw3.lib
│       │   │
│       │   ├───Sandbox
│       │   └───Shmeckle
│       │           Shmeckle.exp
│       │           Shmeckle.lib
│       │
│       ├───CMakeFiles
│       │   │   cmake.check_cache
│       │   │   CMakeConfigureLog.yaml
│       │   │   rules.ninja
│       │   │   TargetDirectories.txt
│       │   │
│       │   ├───3.29.5-msvc4
│       │   │   │   CMakeCCompiler.cmake
│       │   │   │   CMakeCXXCompiler.cmake
│       │   │   │   CMakeDetermineCompilerABI_C.bin
│       │   │   │   CMakeDetermineCompilerABI_CXX.bin
│       │   │   │   CMakeRCCompiler.cmake
│       │   │   │   CMakeSystem.cmake
│       │   │   │
│       │   │   ├───CompilerIdC
│       │   │   │   │   CMakeCCompilerId.c
│       │   │   │   │   CMakeCCompilerId.exe
│       │   │   │   │   CMakeCCompilerId.obj
│       │   │   │   │
│       │   │   │   └───tmp
│       │   │   └───CompilerIdCXX
│       │   │       │   CMakeCXXCompilerId.cpp
│       │   │       │   CMakeCXXCompilerId.exe
│       │   │       │   CMakeCXXCompilerId.obj
│       │   │       │
│       │   │       └───tmp
│       │   ├───pkgRedirects
│       │   └───ShowIncludes
│       │           foo.h
│       │           main.c
│       │           main.obj
│       │
│       ├───Sandbox
│       │   │   cmake_install.cmake
│       │   │
│       │   └───CMakeFiles
│       │       └───Sandbox.dir
│       │           │   CXX.dd
│       │           │   CXXDependInfo.json
│       │           │   CXXModules.json
│       │           │   embed.manifest
│       │           │   intermediate.manifest
│       │           │   manifest.rc
│       │           │   manifest.res
│       │           │   vc140.pdb
│       │           │
│       │           └───source
│       │                   SandboxApplication.cpp.obj
│       │                   SandboxApplication.cpp.obj.ddi
│       │                   SandboxApplication.cpp.obj.modmap
│       │
│       ├───Shmeckle
│       │   │   cmake_install.cmake
│       │   │
│       │   ├───CMakeFiles
│       │   │   └───Shmeckle.dir
│       │   │       │   cmake_pch.cxx
│       │   │       │   cmake_pch.cxx.obj
│       │   │       │   cmake_pch.cxx.pch
│       │   │       │   cmake_pch.hxx
│       │   │       │   CXX.dd
│       │   │       │   CXXDependInfo.json
│       │   │       │   CXXModules.json
│       │   │       │   embed.manifest
│       │   │       │   intermediate.manifest
│       │   │       │   manifest.rc
│       │   │       │   manifest.res
│       │   │       │   vc140.pdb
│       │   │       │
│       │   │       └───source
│       │   │           ├───Platform
│       │   │           │   └───Windows
│       │   │           │           WindowsWindow.cpp.obj
│       │   │           │           WindowsWindow.cpp.obj.ddi
│       │   │           │           WindowsWindow.cpp.obj.modmap
│       │   │           │
│       │   │           └───Shmeckle
│       │   │               │   Application.cpp.obj
│       │   │               │   Application.cpp.obj.ddi
│       │   │               │   Application.cpp.obj.modmap
│       │   │               │   Logger.cpp.obj
│       │   │               │   Logger.cpp.obj.ddi
│       │   │               │   Logger.cpp.obj.modmap
│       │   │               │
│       │   │               ├───Events
│       │   │               │       Event.cpp.obj
│       │   │               │       Event.cpp.obj.ddi
│       │   │               │       Event.cpp.obj.modmap
│       │   │               │       EventHub.cpp.obj.ddi
│       │   │               │       EventHub.cpp.obj.modmap
│       │   │               │
│       │   │               └───Layers
│       │   │                       Layer.cpp.obj
│       │   │                       Layer.cpp.obj.ddi
│       │   │                       Layer.cpp.obj.modmap
│       │   │                       LayerStack.cpp.obj
│       │   │                       LayerStack.cpp.obj.ddi
│       │   │                       LayerStack.cpp.obj.modmap
│       │   │
│       │   └───vendor
│       │       └───GLFW
│       │           │   cmake_install.cmake
│       │           │   cmake_uninstall.cmake
│       │           │
│       │           ├───CMakeFiles
│       │           │   └───Export
│       │           │       └───f367bd07922f2ecfc14cf5547f1f7c4e
│       │           │               glfw3Targets-debug.cmake
│       │           │               glfw3Targets.cmake
│       │           │
│       │           └───src
│       │               │   cmake_install.cmake
│       │               │   glfw3.pc
│       │               │   glfw3Config.cmake
│       │               │   glfw3ConfigVersion.cmake
│       │               │
│       │               └───CMakeFiles
│       │                   └───glfw.dir
│       │                           context.c.obj
│       │                           egl_context.c.obj
│       │                           glfw.pdb
│       │                           init.c.obj
│       │                           input.c.obj
│       │                           monitor.c.obj
│       │                           null_init.c.obj
│       │                           null_joystick.c.obj
│       │                           null_monitor.c.obj
│       │                           null_window.c.obj
│       │                           osmesa_context.c.obj
│       │                           platform.c.obj
│       │                           vulkan.c.obj
│       │                           wgl_context.c.obj
│       │                           win32_init.c.obj
│       │                           win32_joystick.c.obj
│       │                           win32_module.c.obj
│       │                           win32_monitor.c.obj
│       │                           win32_thread.c.obj
│       │                           win32_time.c.obj
│       │                           win32_window.c.obj
│       │                           window.c.obj
│       │
│       └───Testing
│           └───Temporary
│                   LastTest.log
│
```