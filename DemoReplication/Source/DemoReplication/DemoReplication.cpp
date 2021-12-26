// Copyright Epic Games, Inc. All Rights Reserved.

#include "DemoReplication.h"
#include "Modules/ModuleManager.h"
#include "Misc/OutputDevice.h"
#include "GameFramework/PlayerState.h"

IMPLEMENT_PRIMARY_GAME_MODULE(FDefaultGameModuleImpl, DemoReplication, "DemoReplication");

DEFINE_LOG_CATEGORY(Demo)

FString g_Authority = TEXT("N/A");
APlayerState* g_PlayerState = nullptr;


FString GetPlayerID(UWorld* World, const FString& Mark = TEXT(""))
{
	FString Prefix = TEXT("n/a");
	if (World)
	{
		FString IsPIE = TEXT("NPIE");

		if (World->WorldType == EWorldType::PIE)
		{
			IsPIE = TEXT("PIE");
		}

		switch (World->GetNetMode())
		{
		case NM_Client:
			// GPlayInEditorID 0 is always the server, so 1 will be first client.
			// You want to keep this logic in sync with GeneratePIEViewportWindowTitle and UpdatePlayInEditorWorldDebugString
			Prefix = FString::Printf(TEXT("%s-客户端%d"), *IsPIE, GPlayInEditorID);
			break;
		case NM_DedicatedServer:
		case NM_ListenServer:
			Prefix = FString::Printf(TEXT("%s-服务器"), *IsPIE);
			break;
		case NM_Standalone:
			Prefix = FString::Printf(TEXT("%s-Standalone"), *IsPIE);
			break;
		}
	}

	return FString::Printf(TEXT("[%s]-%s"), *Prefix, *Mark);
}

// copy from FString::PrintfImpl

void DemoLog(UObject* Context, const TCHAR* Fmt, ...)
{
#define STARTING_BUFFER_SIZE		512

	int32		BufferSize = STARTING_BUFFER_SIZE;
	TCHAR	StartingBuffer[STARTING_BUFFER_SIZE];
	TCHAR* Buffer = StartingBuffer;
	int32		Result = -1;

	// First try to print to a stack allocated location 
	GET_VARARGS_RESULT(Buffer, BufferSize, BufferSize - 1, Fmt, Fmt, Result);

	// If that fails, start allocating regular memory
	if (Result == -1)
	{
		Buffer = nullptr;
		while (Result == -1)
		{
			BufferSize *= 2;
			Buffer = (TCHAR*)FMemory::Realloc(Buffer, BufferSize * sizeof(TCHAR));
			GET_VARARGS_RESULT(Buffer, BufferSize, BufferSize - 1, Fmt, Fmt, Result);
		};
	}

	Buffer[Result] = 0;

	FString ResultString(Buffer);

	if (BufferSize != STARTING_BUFFER_SIZE)
	{
		FMemory::Free(Buffer);
	}

	FString PlayerInfo = TEXT("N/A");
	if (g_PlayerState)
	{
		UWorld* World = GEngine->GetWorldFromContextObject(g_PlayerState, EGetWorldErrorMode::ReturnNull);
		PlayerInfo = GetPlayerID(World, g_PlayerState->GetHumanReadableName());

	}
	else if (GEngine && GEngine->GetWorld())
	{
		PlayerInfo = GetPlayerID(GEngine->GetWorld(), TEXT("GEngine"));
	}
	else if (GWorld)
	{
		PlayerInfo = GetPlayerID(GWorld, TEXT("GWorld"));
	}
	else if (Context->IsA<AActor>())
	{
		AActor* ActorContext = Cast<AActor>(Context);
		if (ActorContext->HasAuthority())
		{
			PlayerInfo = TEXT("服务器");
		}
		else
		{
			PlayerInfo = TEXT("客户端");
		}
	}
	else
	{
		PlayerInfo = g_Authority;
	}



	FString ContexName = Context->GetName();

	/*FString Authority = TEXT("客户端");

	if (Context->IsA<AActor>())
	{
		AActor* ActorContext = Cast<AActor>(Context);
		if(ActorContext->HasAuthority())
		{
			Authority = TEXT("服务器");
		}
	}*/
	
	SET_WARN_COLOR(COLOR_CYAN);
	//UE_LOG(Demo, Warning, TEXT("[%s] [%s] %s				[%s]"), *Authority, *PlayerInfo, *ResultString, *ContexName);
	UE_LOG(Demo, Warning, TEXT("%s %s				[%s]"), *PlayerInfo, *ResultString, *ContexName);
	CLEAR_WARN_COLOR();
}
