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
	virtual void Destroyed() override;



	virtual void StartPlay() override;

public:
	ADemoReplicationGameMode();

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

};



