workspace "Nova"
architecture "x64"
startproject "SandboxApp"
configurations {"Debug","Release","Dist"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Nova/vendor/glad"
include "Nova/vendor/glfw"

project "Nova"
location "Nova"
kind "StaticLib"
language "C++"
cppdialect "C++17"
staticruntime "on"

targetdir ("bin/" ..outputdir.. "/%{prj.name}")
objdir ("bin-int/" ..outputdir.. "/%{prj.name}")



pchheader "novapch.h"
pchsource "Nova/src/novapch.cpp"

files 
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

links
	{
	"GLFW",
	"Glad",
	"opengl32.lib",


	}


includedirs 
	{
		"%{prj.name}/src",
		"%{prj.name}/src/Nova",
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/glad/include",
		"%{prj.name}/vendor/glfw/include",
		"%{prj.name}/vendor/glm",
		"%{prj.name}/vendor/stbi",

	}


	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/SandboxApp/\"")
	}

filter "system:windows"
	systemversion "latest"
	defines 
	{
		"NOVA_PLATFORM_WINDOWS",
		"NOVA_BUILD_DLL",
		"GLFW_INCLUDE_NONE"
	}

filter "configurations:Debug"
	defines "NOVA_DEBUG"
	symbols "off"
	runtime "Debug"
filter "configurations:Release"
	defines "NOVA_RELEASE"
	symbols "on"
	runtime "Release"
filter "configurations:Dist"
	defines "NOVA_DIST"
	runtime "Release"
	symbols "on"





project "SandBoxApp"
location "SandBoxApp"
kind "ConsoleApp"
language "C++"
cppdialect "C++17"
staticruntime "on"

targetdir ("bin/" ..outputdir.. "/%{prj.name}")
objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

links {"Nova"}

files 
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h",
	}

	includedirs
	{
	"Nova/src",
	"Nova/vendor/spdlog/include",
	"Nova/vendor/glm",
	}

filter "system:windows"
	systemversion "latest"
	defines "NOVA_PLATFORM_WINDOWS"

filter "configurations:Debug"
	defines "NOVA_DEBUG"
	symbols "off"
	runtime "Debug"
filter "configurations:Release"
	defines "NOVA_RELEASE"
	symbols "on"
	runtime "Release"
filter "configurations:Dist"
	defines "NOVA_DIST"
	runtime "Release"
	symbols "on"

