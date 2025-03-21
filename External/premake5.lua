project "googletest"
    targetdir(targetBuildPath .. "/External")
    objdir(objBuildPath .. "/%{prj.name}")

    libraryDir = "\"" .. path.getdirectory(_SCRIPT) .. "\"" .. "/%{prj.name}"

    filter "system:windows"
        kind "Utility"

        filter "configurations:debug"
            prebuildcommands{
                "{MKDIR} %{prj.objdir}",
                "cmake -S " .. libraryDir .. " -B %{prj.objdir} -DCMAKE_INSTALL_PREFIX=%{prj.targetdir} -DCMAKE_MSVC_RUNTIME_LIBRARY='MultiThreadedDebug'",
                "cmake --build %{prj.objdir} --config %{cfg.buildcfg} --target install",
            }

        filter "configurations:release"
            prebuildcommands{
                "{MKDIR} %{prj.objdir}",
                "cmake -S " .. libraryDir .. " -B %{prj.objdir} -DCMAKE_INSTALL_PREFIX=%{prj.targetdir} -DCMAKE_MSVC_RUNTIME_LIBRARY='MultiThreaded'",
                "cmake --build %{prj.objdir} --config %{cfg.buildcfg} --target install",
            }

    filter "system:linux"
        kind "Makefile"

        buildcommands{
            "{MKDIR} %{prj.objdir}",
            "cmake -S " .. libraryDir .. " -B %{prj.objdir} -DCMAKE_INSTALL_PREFIX=%{prj.targetdir}",
            "cmake --build %{prj.objdir} --config %{cfg.buildcfg} --target install",
        }

project "DirectXTK"
    targetdir(targetBuildPath .. "/External")
    objdir(objBuildPath .. "/%{prj.name}")

    configurations { "Debug", "Release" }

    libraryDir = "\"" .. path.getdirectory(_SCRIPT) .. "\"" .. "/%{prj.name}"

    filter "system:windows"
        kind "Utility"

        filter "configurations:debug"
            prebuildcommands{
                "{MKDIR} %{prj.objdir}",
                "cmake -S " .. libraryDir .. " -B %{prj.objdir} -DCMAKE_INSTALL_PREFIX=%{prj.targetdir} -DCMAKE_MSVC_RUNTIME_LIBRARY='MultiThreadedDebug'",
                "cmake --build %{prj.objdir} --config %{cfg.buildcfg} --target install",
            }

        filter "configurations:release"
            prebuildcommands{
                "{MKDIR} %{prj.objdir}",
                "cmake -S " .. libraryDir .. " -B %{prj.objdir} -DCMAKE_INSTALL_PREFIX=%{prj.targetdir} -DCMAKE_MSVC_RUNTIME_LIBRARY='MultiThreaded'",
                "cmake --build %{prj.objdir} --config %{cfg.buildcfg} --target install",
            }

    filter "system:linux"
        kind "Makefile"
        buildcommands{
            "{MKDIR} %{prj.objdir}",
            "cmake -S " .. libraryDir .. " -B %{prj.objdir} -DCMAKE_INSTALL_PREFIX=%{prj.targetdir}",
            "cmake --build %{prj.objdir} --config %{cfg.buildcfg} --target install",
        }

project "ImGui"
    kind "StaticLib"
    targetdir(targetBuildPath .. "/External/lib/")
    objdir(objBuildPath .. "/%{prj.name}")

    files {
        "ImGui/imgui*.cpp",
        "ImGui/backends/imgui_impl_dx11.cpp",
        "ImGui/backends/imgui_impl_win32.cpp"
        --"ImGui/*.h",
        --"ImGui/backends/imgui_impl_dx11.*",
        --"ImGui/backends/imgui_impl_win32.*"
    }

    includedirs{
        "ImGui/",
        "ImGui/backends/"
    }

    mkdirPath = "\"" .. targetBuildPath .. "/External/include/%{prj.name}\""
    copyPath = "\"" .. targetBuildPath .. "/External/include/%{prj.name}\""

    prebuildcommands{
        "{MKDIR} " .. mkdirPath,
        "{COPY} ../External/ImGui/*.h " .. copyPath,
        "{COPY} ../External/ImGui/backends/imgui_impl_dx11.h " .. copyPath,
        "{COPY} ../External/ImGui/backends/imgui_impl_win32.h " .. copyPath
    }

project "APNGLoader"
    kind "StaticLib"
    targetdir(targetBuildPath .. "/External/lib/")
    objdir(objBuildPath .. "/%{prj.name}")

    mkdirPath = "\"" .. targetBuildPath .. "/External/include/%{prj.name}\""
    copyPath = "\"" .. targetBuildPath .. "/External/include/%{prj.name}\""

    prebuildcommands{
        "{MKDIR} " .. mkdirPath,
        "{COPY} ../External/APNGLoader/*.h " .. copyPath
    }

    files {
        "APNGLoader/apng2pngs.cpp"
    }

    includedirs{
        "APNGLoader/"
    }

project "stb"
    kind "StaticLib"

    targetdir(targetBuildPath .. "/External/lib/")
    objdir(objBuildPath .. "/%{prj.name}")

    mkdirPath = "\"" .. targetBuildPath .. "/External/include/%{prj.name}\""
    copyPath = "\"" .. targetBuildPath .. "/External/include/%{prj.name}\""   

    prebuildcommands
    {
        "{MKDIR} " .. mkdirPath,
        "{COPY} ../External/stb/*.h " .. copyPath
    }