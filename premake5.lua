-- premake5.lua

workspace "Shmeckle" -- Is basicly the solution
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

-- Variable
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" -- Look at the tokens page in the wiki

---- Shmeckle --------------------------
project "Shmeckle"
	location "Shmeckle" -- This makes sure we are inside the "Shmeckle" folder
	kind "SharedLib" -- Dynamic library
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/source/**.h",
		"%{prj.name}/source/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/dependencies/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On" -- This has to do with linking the runtime libs (We want to link them staticly)
		systemversion "latest"

		defines
		{
			"SM_PLATFORM_WINDOWS",
			"SM_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox") -- Copies the Shmeckle dll into the Sandbox bin folder after building
		}

		buildoptions "/utf-8"

	filter "configurations:Debug"
		defines "SM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SM_DIST"
		optimize "On"

---- Sandbox ------------------------------
project "Sandbox"
	location "Sandbox" 
	kind "ConsoleApp" -- Executable
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/source/**.h",
		"%{prj.name}/source/**.cpp"
	}

	includedirs
	{
		"Shmeckle/source"
	}

	links
	{
		"Shmeckle"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SM_PLATFORM_WINDOWS"
		}

		buildoptions "/utf-8"

	filter "configurations:Debug"
		defines "SM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SM_DIST"
		optimize "On"