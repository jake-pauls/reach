project "pillar"
	kind "StaticLib"
	language "C"
	cdialect "C17"
	location "%{wks.location}/pillar"

	pchheader "PCH.h"
	pchsource "PCH.c"

	files {
		"%{prj.location}/PCH.**",
		"%{prj.location}/source/**.c",
		"%{prj.location}/include/pillar/**.h",
	}

	vpaths {
		["PCH/*"] = { "**PCH.c", "**PCH.h" },
		["source/**"] = { "source/**.c" },
		["include/**"] = { "include/pillar/**.h" },
	}

	includedirs {
		"%{prj.location}/include/pillar",
		"%{prj.location}",
	}

	filter "system:Windows"
		defines {
			"_CRT_SECURE_NO_WARNINGS",
			"WIN32_LEAN_AND_MEAN",
		}

		-- Force include the PCH on MSVC
		buildoptions { "/FI PCH.h" }

		-- Treat warnings as errors
		flags { "FatalWarnings" }
	filter {}
