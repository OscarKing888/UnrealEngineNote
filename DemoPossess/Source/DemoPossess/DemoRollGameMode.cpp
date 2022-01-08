// Copyright Epic Games, Inc. All Rights Reserved.

#include "DemoRollGameMode.h"
#include "DemoRollBall.h"
#include "DemoCarHud.h"

ADemoRollGameMode::ADemoRollGameMode()
{
	// set default pawn class to our ball
	DefaultPawnClass = ADemoRollBall::StaticClass();
}
