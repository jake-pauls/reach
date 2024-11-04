@echo off
if "%~1" == "-c" goto clean
if "%~1" == "--clean" goto clean

:generate
echo [%~nx0] Generating projects...
call premake5.exe vs2022 --file="Reach/premake5.lua"
goto :eof

:clean
echo [%~nx0] Cleaning build artifacts...
del /S /Q .\Reach\*.vs
del /S /Q .\Reach\*.sln
del /S /Q .\Reach\*.vcxproj
del /S /Q .\Reach\Autumn\build\
goto generate
