project "Autumn"
	kind "WindowedApp"
	language "C++"
	cppdialect "C++20"
	location "%{wks.location}/Autumn"

	pchheader "PCH.h"
	pchsource "PCH.cpp"

	files {
		"%{prj.location}/PCH.**",
		"%{prj.location}/Autumn/**.cpp",
		"%{prj.location}/Autumn/**.h",
	}

	vpaths {
		["PCH/*"] = { "**PCH.cpp", "**PCH.h" },
		["Source/**"] = { "Autumn/**.cpp", "Autumn/**.c" },
		["Include/**"] = { "Autumn/**.hpp", "Autumn/**.h" },
	}

	includedirs {
		"%{prj.location}/Autumn",
		"%{prj.location}",

		"%{prj.location}/../Pillar"
	}

	links {
		"Pillar"
	}

	filter "system:Windows"
		defines { "_CRT_SECURE_NO_WARNINGS" }

		-- Force include the PCH on MSVC
		buildoptions { "/FI PCH.h" }

		-- Treat warnings as errors
		flags { "FatalWarnings" }
	filter {}
