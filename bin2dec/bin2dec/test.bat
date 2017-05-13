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