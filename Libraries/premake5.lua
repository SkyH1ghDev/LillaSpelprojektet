project "Libraries"
    kind "StaticLib"
    targetdir(targetBuildPath .. "/%{prj.name}")
    objdir(objBuildPath .. "/%{prj.name}")
    files {"include/**.hpp", "include/**.h", "src/**.cpp"}
    includedirs{"include/"}