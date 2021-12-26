// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DemoReplicationGameMode.generated.h"

UCLASS(minimalapi)
class ADemoReplicationGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

public:
	ADemoReplicationGameMode();
};



