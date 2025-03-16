## Instruktioner för hur källkoden kan byggas till körbar exe-fil. Fristående spel (en mapp):

### Prerequisites:

Premake5 (https://premake.github.io/)
CMake (https://cmake.org/)

Att manuellt lägga in Premake5 i PATH är rekommenderat för att globalt kunna exekvera kommandot

### Instructions:

1. Öppna bas-mappen till projektet i kommandotolken.
2. Skriv in "premake5 vs2022" för att en solution ska genereras.
3. Gå in i Generated/ mappen och öppna .sln-filen.
3.5. <Optional> Om External/ mappen är tom, skriv:

    
    ```git submodule update --init --recursive --remote```

4. Sätt target build config till "Release x64" och bygg "Application"-projektet. Alla dependencies kommer nu byggas som statiska bibliotek och inkluderas i projektet. Därefter byggs själva motorn och spelet.
5. Gå in i Game/Exe/ mappen och kör spelet