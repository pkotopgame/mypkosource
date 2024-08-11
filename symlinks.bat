:: Server Release
call :MKLINK "C:\Users\amin\Documents\server\AccountServer\AccountServer.exe" "C:\Users\amin\Documents\mypkosource\Server\AccountServer\Bin\AccountServer.exe"
call :MKLINK "C:\Users\amin\Documents\server\AccountServer\AccountServer.pdb" "C:\Users\amin\Documents\mypkosource\Server\AccountServer\Bin\AccountServer.pdb"
call :MKLINK "C:\Users\amin\Documents\server\GroupServer\GroupServer.exe" "C:\Users\amin\Documents\mypkosource\Server\GroupServer\Bin\GroupServer.exe"
call :MKLINK "C:\Users\amin\Documents\server\GroupServer\GroupServer.pdb" "C:\Users\amin\Documents\mypkosource\Server\GroupServer\Bin\GroupServer.pdb"
call :MKLINK "C:\Users\amin\Documents\server\GateServer\GateServer.exe" "C:\Users\amin\Documents\mypkosource\Server\GateServer\Bin\GateServer.exe"
call :MKLINK "C:\Users\amin\Documents\server\GateServer\GateServer.pdb" "C:\Users\amin\Documents\mypkosource\Server\GateServer\Bin\GateServer.pdb"
call :MKLINK "C:\Users\amin\Documents\server\GameServer\GameServer.exe" "C:\Users\amin\Documents\mypkosource\Server\GameServer\Bin\GameServer.exe"
call :MKLINK "C:\Users\amin\Documents\server\GameServer\GameServer.pdb" "C:\Users\amin\Documents\mypkosource\Server\GameServer\Bin\GameServer.pdb"

:: Client Release
call :MKLINK "C:\Users\amin\Documents\client\system\Game.exe" "C:\Users\amin\Documents\mypkosource\Client\bin\system\Game.exe"
call :MKLINK "C:\Users\amin\Documents\client\system\Game.pdb" "C:\Users\amin\Documents\mypkosource\Client\bin\system\Game.pdb"
call :MKLINK "C:\Users\amin\Documents\client\system\MindPower3D_D8R.dll" "C:\Users\amin\Documents\mypkosource\Engine\lib\MindPower3D_D8R.dll"
call :MKLINK "C:\Users\amin\Documents\client\system\MindPower3D_D8R.pdb" "C:\Users\amin\Documents\mypkosource\Engine\lib\MindPower3D_D8R.pdb"

pause

:MKLINK
if exist "%~1" del /F /Q "%~1"
mklink "%~1" "%~2"
EXIT/B 0