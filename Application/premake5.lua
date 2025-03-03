project "Application"
    kind "WindowedApp"

    targetdir(targetBuildPath .. "/%{prj.name}")
    objdir(objBuildPath .. "/%{prj.name}")
    files {"src/**.cpp", "src/**.hpp", "src/**.h", "src/**.hlsl"}

    includedirs{
        "../Library/include/",
        "src/**",
        "src/",
        targetBuildPath .. "/External/include/"
    }

    links
    {
        "Library",
        "d3d11",
        "d3dcompiler",
        "DXGI",
        targetBuildPath .. "/External/lib/DirectXTK",
        targetBuildPath .. "/External/lib/ImGui"
    }

    filter "configurations:release"
        postbuildcommands{
            "{MKDIR} " .. gameCopyPath,
            "{COPY} ../Application/Resources " .. gameCopyPath,
            "{COPY} " .. targetBuildPath .. "/Application/Application.exe " .. gameCopyPath
        }


    