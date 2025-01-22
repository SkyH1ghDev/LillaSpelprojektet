project "Libraries"
    kind "StaticLib"
    targetdir(targetBuildPath .. "/%{prj.name}")
    objdir(objBuildPath .. "/%{prj.name}")
    files {"src/**.cpp", "include/**.hpp", "include/**.h"}
    includedirs{"include/DirectXTK/Inc/", "include/"}