workspace "Funtal"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Funtal"
	location "Funtal"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.26100.0"

	defines
	{
		"FT_PLATFORM_WINDOWS",
		"FT_BUILD_DLL"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "FT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FT_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Funtal/vendor/spdlog/include",
		"Funtal/src"
	}

	links
	{
		"Funtal"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

	defines
	{
		"FT_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "FT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FT_DIST"
		optimize "On"