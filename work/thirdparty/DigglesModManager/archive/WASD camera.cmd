@echo off
title Diggles - WASD camera
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0apply-wasd-camera.ps1"
echo.
echo If the list above shows A=25 D=27 S=28 W=26 - the patch is active.
echo Press any key to start the game...
pause >nul
set SteamAppId=1478650
set SteamGameId=1478650
start "" "%~dp0Diggles.exe"
