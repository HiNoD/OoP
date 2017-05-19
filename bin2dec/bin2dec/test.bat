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