set GLPATH=..\..\..\..\common
xcopy %GLPATH%\GL\*.*        .\GL\*.*        /e/y
xcopy %GLPATH%\Debug\*.*    ..\Debug\*.*     /e/y
pause