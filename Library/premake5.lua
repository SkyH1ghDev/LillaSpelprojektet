project "Library"
    kind "StaticLib"
    targetdir(targetBuildPath .. "/%{prj.name}")
    objdir(objBuildPath .. "/%{prj.name}")

    dependson{"DirectXTK"}
    dependson{"ImGui"}

    files {
        "src/**.cpp",
        "include/**.hpp",
        "include/**.h"
    }

    includedirs{
        "include/**",
        "include/",
        "../External/stb",
        targetBuildPath .. "/External/include/"
    }
