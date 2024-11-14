workspace "reach"
	architecture "x64"
	configurations { "Debug", "Release" }
	startproject "autumn"

	targetdir "%{wks.location}/%{prj.name}/__build/bin/%{cfg.buildcfg}"
	objdir "%{wks.location}/%{prj.name}/__build/obj/%{cfg.buildcfg}"

	vpaths {
		["./"] = { "**premake5.lua" }
	}

	filter "system:Windows"
		defines { "WIN32" }
	filter "configurations:Debug"
		defines { "RDEBUG" }
		runtime "Debug"
		symbols "On"
	filter "configurations:Release"
		defines { "RRELEASE" }
		runtime "Release"
		optimize "On"
		symbols "Off"
	filter {}

-- Engine
include "pillar"
-- Game
include "autumn"
