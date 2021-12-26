// Copyright Epic Games, Inc. All Rights Reserved.

#include "DemoReplicationGameMode.h"
#include "DemoReplication.h"
#include "DemoReplicationPlayerController.h"
#include "DemoReplicationCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADemoReplicationGameMode::ADemoReplicationGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ADemoReplicationPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	DemoLog(this, TEXT("[Init][ADemoReplicationGameMode::Ctor]"));
}



void ADemoReplicationGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	DemoLog(this, TEXT("[Init][ADemoReplicationGameMode::InitGame][%s]"), *MapName);

	// 重载函数一定要调用底层，不管有没有功能，养成习惯免得漏掉
	Super::InitGame(MapName, Options, ErrorMessage);
}

void ADemoReplicationGameMode::BeginPlay()
{
	DemoLog(this, TEXT("[Init][ADemoReplicationGameMode::BeginPlay]"));

	// 重载函数一定要调用底层，不管有没有功能，养成习惯免得漏掉
	Super::BeginPlay();
}

void ADemoReplicationGameMode::Destroyed()
{
	DemoLog(this, TEXT("[Init][ADemoReplicationGameMode::Destroyed]"));

	// 重载函数一定要调用底层，不管有没有功能，养成习惯免得漏掉
	Super::Destroyed();

}

void ADemoReplicationGameMode::StartPlay()
{
	if (this->HasAuthority())
	{
		g_Authority = TEXT("GameMode[服务器]");
	}
	else
	{
		g_Authority = TEXT("GameMode[客户端]");
	}

	DemoLog(this, TEXT("[Init][ADemoReplicationGameMode::StartPlay]"));

	// 重载函数一定要调用底层，不管有没有功能，养成习惯免得漏掉
	Super::StartPlay();
}
