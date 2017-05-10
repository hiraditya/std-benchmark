@echo off

:: %HOMEDRIVE%
:: cd %HOMEPATH%

echo "Calling vcvars"

:: Initialize environment variables by calling vcvars. Your compiler may have this
:: batch file somewhere else. Please change this appropriately.
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary/Build/vcvars64.bat"
:: READ README.md for more info

::call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary/Build/vcvars32.bat"


echo Use full exe names when running under bash, e.g. "msbuild.exe"
echo Loading bash, you may now use git and msbuild in the same console \o/.

:: "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Git\Git Bash" --login -i

:: Invoke git-bash from this environment such that git-bash inherits it.
"C:\Program Files\Git\git-bash.exe"
