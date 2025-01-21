project "Application"
    kind "WindowedApp"
    targetdir(targetBuildPath .. "/%{prj.name}")
    objdir(objBuildPath .. "/%{prj.name}")
    files {"src/**.hpp", "src/**.h", "src/**.cpp"}
    includedirs{"../Libraries/include"}

    links{"Libraries"}