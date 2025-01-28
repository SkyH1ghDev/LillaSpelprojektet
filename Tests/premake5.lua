project "Tests"
    kind "ConsoleApp"
    targetdir(targetBuildPath .. "/%{prj.name}")
    objdir(objBuildPath .. "/%{prj.name}")
    files {"src/**"}

    includedirs{
        "../Library/include/**",
        "../Library/include/",
        "../External/googletest/googletest/include/",
        targetBuildPath .. "/External/include/"
    }

    -- Although this consoleApp does not link to the "googletest" project per say, it is still dependant on its build to finish
    dependson{"googletest"}

    links{
        "Library",
        "d3d11",
        "DXGI",
        "d3dcompiler",
        targetBuildPath .. "/External/lib/gtest",
        targetBuildPath .. "/External/lib/DirectXTK"
    }
