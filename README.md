# UnrealEngineNote


## 打开SHIPPING LOG

    bUseLoggingInShipping = true;

## 增加Build Target

    Source/XXX.Target.cs -> XXXServer.Target.cs

    Type = TargetType.Server;


## 配置开启LOG
    -LogCmds="LogOnline All"
    [Core.Log]
    LogOnline=All

## URL命令行传入
    -Port=8888

    BaseEngine.ini
    - [URL]
    - Protocol=unreal
    - Name=Player
	- SaveExt=usa
	- Port=7777


```c++
void FUrlConfig::Init()
{
	DefaultProtocol = GConfig->GetStr( TEXT("URL"), TEXT("Protocol"), GEngineIni );
	DefaultName = GConfig->GetStr( TEXT("URL"), TEXT("Name"), GEngineIni );
	// strip off any file extensions from map names
	DefaultHost = GConfig->GetStr( TEXT("URL"), TEXT("Host"), GEngineIni );
	DefaultPortal = GConfig->GetStr( TEXT("URL"), TEXT("Portal"), GEngineIni );
	DefaultSaveExt = GConfig->GetStr( TEXT("URL"), TEXT("SaveExt"), GEngineIni );
	
	FString Port;
	// Allow the command line to override the default port
	if (FParse::Value(FCommandLine::Get(),TEXT("Port="),Port) == false)
	{
		Port = GConfig->GetStr( TEXT("URL"), TEXT("Port"), GEngineIni );
	}
	DefaultPort = FCString::Atoi( *Port );
}
```


## 协议类型
    unreal:192.168.0.1:7776
    steam.76561197993275299:20/
    https:[2001:db8:85a3::8a2e:370:7334]:443


## Warning: SetReplicates called on non-initialized actor
```c++
Just change SetReplicates(true); to '''bReplicates = true;''' in the constructor.
```


## 判定是否运行在服务器上
```c++
/** Returns whether the world this object is in is the host or not */
UFUNCTION(BlueprintPure, Category="Networking", meta=(WorldContext="WorldContextObject") )
static bool IsServer(const UObject* WorldContextObject);

/** Returns whether this is running on a dedicated server */
UFUNCTION(BlueprintPure, Category="Networking", meta=(WorldContext="WorldContextObject"))
static bool IsDedicatedServer(const UObject* WorldContextObject);

/** Returns whether this game instance is stand alone (no networking). */
UFUNCTION(BlueprintPure, Category="Networking", meta=(WorldContext="WorldContextObject"))
static bool IsStandalone(const UObject* WorldContextObject);

bool UKismetSystemLibrary::IsServer(const UObject* WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	return World ? (World->GetNetMode() != NM_Client) : false;
}
```

## 默认地图配置及调用的代码 
```c++
//UnrealEngine\Engine\Source\Runtime\EngineSettings\Classes\GameMapsSettings.h
UGameMapsSettings
	static FString GetGameDefaultMap( );
	static FString GetGlobalDefaultGameMode( );
```
