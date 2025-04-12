@echo off
cd /d "%~dp0"

echo ============================
echo Compiling C++ project...
echo ============================

g++ -std=c++17 -o temple.exe ^
    main.cpp ^
    TempleManagementSystem.cpp ^
    Person.cpp ^
    Admin.cpp ^
    Staff.cpp ^
    Devotee.cpp ^
    ReligiousEvent.cpp

if %errorlevel% neq 0 (
    echo.
    echo  Compile error!
    pause
    exit /b
)

echo.
echo  Compile success!
echo ============================
echo Launching in new console...
echo ============================

REM Mở cửa sổ console mới và chạy chương trình
start cmd /k temple.exe
