workspace "Lowme"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Lowme"
	location "Lowme"
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
		systemversion "10.0"

		defines
		{
			"LM_PLATFORM_WINDOWS",
			"LM_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Soulou")
		}

	filter "configurations:Debug"
		defines "LM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LM_DIST"
		optimize "On"

project "Soulou"
	location "Soulou"
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
		"Lowme/vendor/spdlog/include",
		"Lowme/src"
	}

	links
	{
		"Lowme"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"

		defines
		{
			"LM_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "LM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LM_DIST"
		optimize "On"