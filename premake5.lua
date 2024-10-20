workspace "MCompiler"
	architecture "x86_64"
	configurations { "Debug", "Release" }

project "MCompiler"
	location "."
	targetname "mcr"

	kind "ConsoleApp"
	language "C++"
    cppdialect "C++20"

	targetdir "bin/%{cfg.buildcfg}"
	objdir "bin/obj/%{cfg.buildcfg}"

	files { "src/**.h", "src/**.cpp" }
	
	includedirs {
		"src",
		"libs/spdlog/include"
	}

	filter "configurations:Debug"
        defines { "MC_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "MC_RELEASE" }
        optimize "On"