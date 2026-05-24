@echo off
cls

echo ============================
echo   EDU OS FULL SYSTEM RUN
echo ============================

echo Running Python Scheduler...

cd /d "%~dp0python_scheduler"
if exist scheduler_sim.py (
    python scheduler_sim.py
) else (
    echo ERROR: scheduler_sim.py not found
)

echo.
echo Running C Scheduler...

cd /d "%~dp0c_core"

if exist eduos.exe (
    eduos.exe
) else (
    echo ERROR: eduos.exe not found
    echo Trying to compile...
    gcc main_sim.c -o eduos.exe
    eduos.exe
)

pause