project "Pillar"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	location "%{wks.location}/Pillar"

	pchheader "PCH.h"
	pchsource "PCH.cpp"

	files {
		"%{prj.location}/PCH.**",
		"%{prj.location}/Pillar/**.cpp",
		"%{prj.location}/Pillar/**.h",
	}

	vpaths {
		["PCH/*"] = { "**PCH.cpp", "**PCH.h" },
		["Source/**"] = { "Pillar/**.cpp", "Pillar/**.c" },
		["Include/**"] = { "Pillar/**.hpp", "Pillar/**.h" },
	}

	includedirs {
		"%{prj.location}/Pillar",
		"%{prj.location}",
	}

	filter "system:Windows"
		defines { "_CRT_SECURE_NO_WARNINGS" }

		-- Force include the PCH on MSVC
		buildoptions { "/FI PCH.h" }

		-- Treat warnings as errors
		flags { "FatalWarnings" }
	filter {}
