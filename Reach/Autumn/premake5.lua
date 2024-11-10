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
