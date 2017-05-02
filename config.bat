

@echo off

:: %HOMEDRIVE%
:: cd %HOMEPATH%

REM "-DCMAKE_C_COMPILER=C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/VC/Tools/MSVC/14.10.25017/bin/HostX86/x86/cl.exe -DCMAKE_CXX_COMPILER=C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/VC/Tools/MSVC/14.10.25017/bin/HostX86/x86/cl.exe"

REM "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.10.25017\bin\HostX86\x86\cl.exe"

echo "Calling vcvars"

:: dir "C:/Program Files (x86)\Microsoft Visual Studio\2017\Community\Common\Tools\vsdevcmd"

cmd /c "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common\Tools\vsdevcmd\ext\vcvars.bat" x86

REM call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat" x86
echo Use full exe names when running under bash, e.g. "msbuild.exe"
echo Loading bash, you may now use git and msbuild in the same console \o/.

:: "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Git\Git Bash" --login -i

"C:\Program Files\Git\git-bash.exe"
