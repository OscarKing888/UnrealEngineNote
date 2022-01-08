// Copyright Epic Games, Inc. All Rights Reserved.

#include "DemoCarGameMode.h"
#include "DemoCarPawn.h"
#include "DemoCarHud.h"

ADemoCarGameMode::ADemoCarGameMode()
{
	DefaultPawnClass = ADemoCarPawn::StaticClass();
	HUDClass = ADemoCarHud::StaticClass();
}
