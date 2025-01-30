project "Application"
    kind "WindowedApp"

    targetdir(targetBuildPath .. "/%{prj.name}")
    objdir(objBuildPath .. "/%{prj.name}")
    files {"src/**.cpp", "src/**.hpp", "src/**.h", "src/**.hlsl"}

    includedirs{
        "../Library/include/",
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

    filter {"files:**.hlsl"}
        shadermodel("5.0")
        buildaction("FxCompile")
    filter {"files:vs**.hlsl"}
        shadertype "Vertex"
    filter {"files:ps**.hlsl"}
        shadertype "Pixel"
    filter {"files:hs**.hlsl"}
        shadertype "Hull"
    filter {"files:gs**.hlsl"}
        shadertype "Geometry"
    filter {"files:ds**.hlsl"}
        shadertype "Domain"
    filter {"files:cs**.hlsl"}
        shadertype "Compute"
