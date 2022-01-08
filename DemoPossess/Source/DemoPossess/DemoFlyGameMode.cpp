// Copyright Epic Games, Inc. All Rights Reserved.

#include "DemoFlyGameMode.h"
#include "DemoFlyPawn.h"

ADemoFlyGameMode::ADemoFlyGameMode()
{
	// set default pawn class to our flying pawn
	DefaultPawnClass = ADemoFlyPawn::StaticClass();
}
