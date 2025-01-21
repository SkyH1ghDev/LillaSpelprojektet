project "Application"
    kind "WindowedApp"
    targetdir(targetBuildPath .. "/%{prj.name}")
    objdir(objBuildPath .. "/%{prj.name}")
    files {"src/**.cpp", "src/**.hpp", "src/**.h"}
    includedirs{"../Libraries/include/**", "../Libraries/include/**", "src/**", "src/**"}

    links{"Libraries"}