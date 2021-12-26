set ue4="C:\Program Files\Epic Games\UE_4.27\Engine\Binaries\Win64\UE4Editor-Cmd.exe"
set prj="%cd%\DemoReplication.uproject"

%ue4%  %prj%  127.0.0.1 -Game -log -res=640x480w

pause