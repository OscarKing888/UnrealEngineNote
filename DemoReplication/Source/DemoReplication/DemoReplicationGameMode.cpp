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
}



void ADemoReplicationGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (this->HasAuthority())
	{
		LogTag = TEXT("GameMode[服务器]");
	}
	else
	{
		LogTag = TEXT("GameMode[客户端]");
	}

	DemoLog(TEXT("[GameMode::BeginPlay]"));

}
