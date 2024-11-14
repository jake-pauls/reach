project "autumn"
	kind "WindowedApp"
	language "C"
	cdialect "C17"
	location "%{wks.location}/autumn"

	pchheader "PCH.h"
	pchsource "PCH.c"

	files {
		"%{prj.location}/PCH.**",
		"%{prj.location}/source/**.c",
		"%{prj.location}/include/autumn/**.h",
	}

	vpaths {
		["PCH/*"] = { "**PCH.c", "**PCH.h" },
		["source/**"] = { "source/**.c" },
		["include/**"] = { "include/autumn/**.h" },
	}

	includedirs {
		"%{prj.location}/include/autumn",
		"%{prj.location}",

		"%{prj.location}/../pillar/include"
	}

	links {
		"pillar"
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

		links {
			"user32", -- Win32
			"d3d11", -- Direct3D
			"dxgi", -- DirectX Graphics Interface
			"d3dcompiler", -- Shader Compiler
		}
	filter {}