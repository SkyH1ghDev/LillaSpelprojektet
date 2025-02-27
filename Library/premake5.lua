project "Library"
    kind "StaticLib"
    targetdir(targetBuildPath .. "/%{prj.name}")
    objdir(objBuildPath .. "/%{prj.name}")

    dependson{"DirectXTK", "ImGui", "stb"}

    files {
        "src/**.cpp",
        "include/**.hpp",
        "include/**.h"
    }

    includedirs{
        "include/**",
        "include/",
        "../Application/src/Game/",
        "../External/stb",
        targetBuildPath .. "/External/include/"
    }
