set ue4="C:\Program Files\Epic Games\UE_4.27\Engine\Binaries\Win64\UE4Editor-Cmd.exe"
set prj="%cd%\DemoReplication.uproject"
set map=/Game/TopDownCPP/Maps/TopDownExampleMap?

%ue4%  %prj%  %map% -Server -log

pause