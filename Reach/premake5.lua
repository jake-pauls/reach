workspace "Reach"
	architecture "x64"
	configurations { "Debug", "Release" }
	startproject "Autumn"

	targetdir "%{wks.location}/%{prj.name}/build/bin/%{cfg.buildcfg}"
	objdir "%{wks.location}/%{prj.name}/build/obj/%{cfg.buildcfg}"

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

include "Pillar"
include "Autumn"
