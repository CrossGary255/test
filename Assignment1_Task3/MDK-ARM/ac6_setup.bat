@echo off
rem ---------------------------------------------------------------
rem  Re-apply the ARM Compiler 6 (armclang) configuration after
rem  CubeMX "GENERATE CODE" or after changing the MCU.
rem  Optional: stack size, e.g.   ac6_setup.bat 0x2000
rem ---------------------------------------------------------------
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0ac6_setup.ps1" %*
pause