-- premake5.lua

workspace "Shmeckle" -- Is basicly the solution
	architecture "x64"

	configurations
	{
		"Analyze",
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

	pchheader "shmpch.h"
	pchsource "%{prj.name}/source/shmpch.cpp" -- Visual studio needed

	files
	{
		"%{prj.name}/source/**.h",
		"%{prj.name}/source/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/dependencies/spdlog/include",
		"%{prj.name}/source"
	}

	externalincludedirs
	{
		"%{prj.name}/dependencies/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On" -- This has to do with linking the runtime libs (We want to link them staticly)
		systemversion "latest"

		defines
		{
			"SHM_PLATFORM_WINDOWS",
			"SHM_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox") -- Copies the Shmeckle dll into the Sandbox bin folder after building
		}

		buildoptions "/utf-8"

	filter "configurations:Analyze"
		runcodeanalysis "On"
		buildoptions "/analyze:external-"
		warnings "Extra"
		externalwarnings "Default"
		fatalwarnings "All"
		vsprops { CodeAnalysisRuleSet = "../codeAnalysis/Shmeckle.ruleset" }
		defines "SHM_ANALYZE"
		symbols "On"

	filter "configurations:Debug"
		warnings "Extra"
		externalwarnings "Default"
		defines "SHM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SHM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SHM_DIST"
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
		defines	"SHM_PLATFORM_WINDOWS"
		buildoptions "/utf-8"

	filter "configurations:Analyze"
		runcodeanalysis "On"
		warnings "Extra"
		fatalwarnings "All"
		vsprops { CodeAnalysisRuleSet = "../codeAnalysis/Shmeckle.ruleset" }
		defines "SHM_ANALYZE"
		symbols "On"

	filter "configurations:Debug"
		warnings "Extra"
		defines "SHM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SHM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SHM_DIST"
		optimize "On"