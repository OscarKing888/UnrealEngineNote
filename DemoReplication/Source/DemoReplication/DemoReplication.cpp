// Copyright Epic Games, Inc. All Rights Reserved.

#include "DemoReplication.h"
#include "Modules/ModuleManager.h"
#include "Misc/OutputDevice.h"
#include "GameFramework/PlayerState.h"

IMPLEMENT_PRIMARY_GAME_MODULE(FDefaultGameModuleImpl, DemoReplication, "DemoReplication");

DEFINE_LOG_CATEGORY(LogDemoReplication)

FString LogTag = TEXT("N/A");
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
			Prefix = FString::Printf(TEXT("%s-Client%d"), *IsPIE, GPlayInEditorID);
			break;
		case NM_DedicatedServer:
		case NM_ListenServer:
			Prefix = FString::Printf(TEXT("%s-Server"), *IsPIE);
			break;
		case NM_Standalone:
			Prefix = FString::Printf(TEXT("%s-Standalone"), *IsPIE);
			break;
		}
	}

	return FString::Printf(TEXT("%s-%s"), *Prefix, *Mark);
}

// copy from FString::PrintfImpl

void DemoLog(const TCHAR* Fmt, ...)
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
	else if (GEngine->GetWorld())
	{
		PlayerInfo = GetPlayerID(GEngine->GetWorld(), TEXT("GEngine"));
	}
	else if (GWorld)
	{
		PlayerInfo = GetPlayerID(GWorld, TEXT("GWorld"));
	}

	SET_WARN_COLOR(COLOR_CYAN);
	//UE_LOG(LogHAL, SetColor, TEXT("%s"), COLOR_CYAN)
	UE_LOG(LogDemoReplication, Warning, TEXT("%s [%s] %s"), *LogTag, *PlayerInfo, *ResultString);
	CLEAR_WARN_COLOR();
	//UE_LOG(LogHAL, SetColor, TEXT("%s"), COLOR_NONE);
}
