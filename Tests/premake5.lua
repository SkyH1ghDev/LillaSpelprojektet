project "Tests"
    kind "ConsoleApp"
    targetdir(targetBuildPath .. "/%{prj.name}")
    objdir(objBuildPath .. "/%{prj.name}")
    files {"src/**"}
    includedirs{"../Libraries/include/**", "../Libraries/include/", "../External/googletest/googletest/", "../External/googletest/googletest/include"}

    libdirs{targetBuildPath .. "/googletest"}

    -- Although this consoleApp does not link to the "googletest" project per say, it is still dependant on its build to finish
    links{"Libraries", "gtest", "googletest"}