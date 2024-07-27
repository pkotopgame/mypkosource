:: Server Release
call :MKLINK "C:\topnet\server\AccountServer\AccountServer.exe" C:\topnet\sources\Server\AccountServer\Bin\AccountServer.exe"
call :MKLINK "C:\topnet\server\AccountServer\AccountServer.pdb" "C:\topnet\sources\Server\AccountServer\Bin\AccountServer.pdb"
call :MKLINK "C:\topnet\server\GroupServer\GroupServer.exe" "C:\topnet\sources\Server\GroupServer\Bin\GroupServer.exe"
call :MKLINK "C:\topnet\server\GroupServer\GroupServer.pdb" "C:\topnet\sources\Server\GroupServer\Bin\GroupServer.pdb"
call :MKLINK "C:\topnet\server\GateServer\GateServer.exe" "C:\topnet\sources\Server\GateServer\Bin\GateServer.exe"
call :MKLINK "C:\topnet\server\GateServer\GateServer.pdb" "C:\topnet\sources\Server\GateServer\Bin\GateServer.pdb"
call :MKLINK "C:\topnet\server\GameServer\GameServer.exe" "C:\topnet\sources\Server\GameServer\Bin\GameServer.exe"
call :MKLINK "C:\topnet\server\GameServer\GameServer.pdb" "C:\topnet\sources\Server\GameServer\Bin\GameServer.pdb"

:: Client Release
call :MKLINK "C:\topnet\client\system\Game.exe" "C:\topnet\sources\Client\bin\system\Game.exe"
call :MKLINK "C:\topnet\client\system\Game.pdb" "C:\topnet\sources\Client\bin\system\Game.pdb"
call :MKLINK "C:\topnet\client\system\MindPower3D_D8R.dll" "C:\topnet\sources\Engine\lib\MindPower3D_D8R.dll"
call :MKLINK "C:\topnet\client\system\MindPower3D_D8R.pdb" "C:\topnet\sources\Engine\lib\MindPower3D_D8R.pdb"

pause

:MKLINK
if exist "%~1" del /F /Q "%~1"
mklink "%~1" "%~2"
EXIT/B 0