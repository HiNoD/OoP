<<<<<<< HEAD
SET program="%1"
if %program% == "" goto err

echo Test1
bin2dec.exe %TEMP%\1111111111111111111111111111111 1111111111111111111111111111111
if ERRORLEVEL 1 goto testFailed

echo Test3
bin2dec.exe %TEMP%\110010000 110010000
if ERRORLEVEL 1 goto testFailed

echo Test4
bin2dec.exe %TEMP%\000 000
if ERRORLEVEL 1 goto testFailed

echo Test5
bin2dec.exe %TEMP%\224
if ERRORLEVEL 1 goto testFailed

echo Programm testing succeeded
exit 0

:testFailed
echo Testing failed
exit 1;
=======
rem @echo off
SET program="%1"
if %program% == "" goto err

mkdir Out
echo Test1
%program% 110010000 >> out1.txt
if ERRORLEVEL 1 goto testFailed

echo Test2
%program% 1111111 >> out2.txt
if ERRORLEVEL 1 goto testFailed

echo Test3 
%program% 000 >> out3.txt
if ERRORLEVEL 1 goto testFailed

echo Test4
%program%   >> out4.txt
if ERRORLEVEL 1 goto testFailed

echo OK
exit /B

:testFailed
echo Testing failed

:err
echo Usage: test.bat <Path to program>;
>>>>>>> origin/master
