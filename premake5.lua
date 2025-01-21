require "clean"
require "vscode"

workspace "LillaSpelprojektet"
    location "Generated"
    cppdialect "C++20"
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

include "External"
include "Libraries"
include "Application"
include "Tests"