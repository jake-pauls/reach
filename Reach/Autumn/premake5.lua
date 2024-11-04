project "Autumn"
	kind "WindowedApp"
	language "C++"
	cppdialect "C++20"
	location "%{wks.location}/Autumn"

	pchheader "PCH.h"
	pchsource "PCH.cpp"

	files {
		"%{prj.location}/PCH.**",
		"%{prj.location}/Source/**.cpp",
		"%{prj.location}/Source/**.h",
	}

	vpaths {
		["PCH/*"] = { "**PCH.cpp", "**PCH.h" },
		["Source/**"] = { "Source/**.cpp", "Source/**.c" },
		["Headers/**"] = { "Source/**.hpp", "Source/**.h" },
	}

	includedirs {
		"%{prj.location}/Source",
		"%{prj.location}",
	}

	filter "system:Windows"
		defines { "_CRT_SECURE_NO_WARNINGS" }

		-- Force include the PCH on MSVC
		buildoptions { "/FI PCH.h" }

		-- Treat warnings as errors
		flags { "FatalWarnings" }
	filter {}
