@echo off
call setEnv.bat
"D:\MATLAB\R2021b\toolbox\shared\coder\ninja\win64\ninja.exe" -t compdb cc cxx cudac > compile_commands.json
"D:\MATLAB\R2021b\toolbox\shared\coder\ninja\win64\ninja.exe" -v %*
