@echo off
echo Choose:
echo [A] Set 10.0.27.6 as IP
echo [B] Set IP Automatically
echo [C] Set Driver Station IP
echo [D] Set Camera IP
echo.
:choice
SET /P E=[A,B,C,D]?
for %%? in (A) do if /I "%E%"=="%%?" goto A
for %%? in (B) do if /I "%E%"=="%%?" goto B
for %%? in (C) do if /I "%E%"=="%%?" goto C
for %%? in (D) do if /I "%E%"=="%%?" goto D
goto choice
:A
@echo off
echo Setting IP to 10.0.27.6 and Subnet Mask to 255.0.0.0
netsh interface ip set address "Local Area Connection" static 10.0.27.6 255.0.0.0
netsh int ip show config
pause
goto end

:B
@ECHO OFF
ECHO Resetting IP Address and Subnet Mask For DHCP
netsh int ip set address name = "Local Area Connection" source = dhcp
ipconfig /renew
ECHO Here are the new settings for %computername%:
netsh int ip show config
pause
goto end

:C
@echo off
echo Setting IP to 10.0.27.5 and Subnet Mask to 255.0.0.0
netsh interface ip set address "Local Area connection" static 10.0.27.5 255.0.0.0
netsh int ip show config
pause
goto end

:D
@echo off
echo Setting IP to 192.169.0.89 and Subnet Mask to 255.0.0.0
netsh interface ip set address "Local Area connection" static 192.168.0.89 255.0.0.0
netsh int ip show config
pause
goto end

:end