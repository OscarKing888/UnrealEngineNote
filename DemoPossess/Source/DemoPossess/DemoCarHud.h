// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/HUD.h"
#include "DemoCarHud.generated.h"


UCLASS(config = Game)
class ADemoCarHud : public AHUD
{
	GENERATED_BODY()

public:
	ADemoCarHud();

	/** Font used to render the vehicle info */
	UPROPERTY()
	UFont* HUDFont;

	// Begin AHUD interface
	virtual void DrawHUD() override;
	// End AHUD interface
};
