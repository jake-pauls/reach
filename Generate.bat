@echo off
if "%~1" == "-c" goto clean
if "%~1" == "--clean" goto clean

:generate
echo [%~nx0] Generating projects...
call .\reach\third_party\premake\premake5.exe vs2022 --file="reach/premake5.lua"
goto :eof

:clean
echo [%~nx0] Cleaning build artifacts...
del /S /Q .\reach\.vs\
del /S /Q .\reach\*.sln
del /S /Q .\reach\*.vcxproj
del /S /Q .\reach\autumn\__build\
del /S /Q .\reach\autumn\*.vcxproj*
del /S /Q .\reach\pillar\__build\
del /S /Q .\reach\pillar\*.vcxproj*
goto generate
