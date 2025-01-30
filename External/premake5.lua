project "googletest"
    targetdir(targetBuildPath .. "/External")
    objdir(objBuildPath .. "/%{prj.name}")

    libraryDir = "\"" .. path.getdirectory(_SCRIPT) .. "\"" .. "/%{prj.name}"
    
    filter "system:windows"
        kind "Utility"
        prebuildcommands{
            "{MKDIR} %{prj.objdir}",
            "cmake -S " .. libraryDir .. " -B %{prj.objdir} -DCMAKE_INSTALL_PREFIX=%{prj.targetdir} -DCMAKE_MSVC_RUNTIME_LIBRARY='MultiThreadedDebug'",
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
    
    libraryDir = "\"" .. path.getdirectory(_SCRIPT) .. "\"" .. "/%{prj.name}"
    
    filter "system:windows"
        kind "Utility"
        prebuildcommands{
            "{MKDIR} %{prj.objdir}",
            "cmake -S " .. libraryDir .. " -B %{prj.objdir} -DCMAKE_INSTALL_PREFIX=%{prj.targetdir} -DCMAKE_MSVC_RUNTIME_LIBRARY='MultiThreadedDebug'",
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
        "ImGui/imgui*.cpp"
        --"ImGui/*.h",
        --"ImGui/backends/imgui_impl_dx11.*",
        --"ImGui/backends/imgui_impl_win32.*"
    }
    
    includedirs{
        "ImGui/",
        "ImGui/backends/"
    }
    
    prebuildcommands{
        "{MKDIR} " .. targetBuildPath .. "/External/include/%{prj.name}",
        "{COPY} ../External/ImGui/*.h " .. targetBuildPath .. "/External/include/%{prj.name}",
        "{COPY} ../External/ImGui/backends/imgui_impl_dx11.h " .. targetBuildPath .. "/External/include/%{prj.name}",
        "{COPY} ../External/ImGui/backends/imgui_impl_win32.h " .. targetBuildPath .. "/External/include/%{prj.name}"
    }
