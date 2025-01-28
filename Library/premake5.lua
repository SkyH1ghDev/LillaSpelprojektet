project "Library"
    kind "StaticLib"
    targetdir(targetBuildPath .. "/%{prj.name}")
    objdir(objBuildPath .. "/%{prj.name}")

    dependson{"DirectXTK"}

    files {
        "src/**.cpp",
        "include/**.hpp",
        "include/**.h"
    }

    includedirs{
        "include/**",
        "include/",
        "../External/",
        targetBuildPath .. "/External/include/"
    }
