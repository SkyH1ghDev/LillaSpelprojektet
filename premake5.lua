require "clean"
require "vscode"

workspace "LillaSpelprojektet"
    cppdialect "C++20"
    location "Generated"
    configurations
    {
        "debug",
        "release"
    }

    architecture "x86_64"
    staticruntime "on"

    filter "configurations:debug"
        runtime "Debug"
        defines { "DEBUG" }
        symbols "On"
    filter "configurations:release"
        runtime "Release"
        defines { "NDEBUG" }
        optimize "On"

    targetBuildPath = path.getdirectory(_SCRIPT) .. "/Build/target"
    objBuildPath = path.getdirectory(_SCRIPT) .. "/Build/obj"
    gameCopyPath = path.getdirectory(_SCRIPT) .. "/Game"

include "External"
include "Library"
include "Application"
include "Tests" 