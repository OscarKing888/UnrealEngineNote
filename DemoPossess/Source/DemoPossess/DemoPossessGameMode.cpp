// Copyright Epic Games, Inc. All Rights Reserved.

#include "DemoPossessGameMode.h"
#include "DemoPossessCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "DemoCarHud.h"

ADemoPossessGameMode::ADemoPossessGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}


	HUDClass = ADemoCarHud::StaticClass();
}
