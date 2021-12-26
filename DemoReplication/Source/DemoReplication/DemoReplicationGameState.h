// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "DemoReplicationGameState.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class DEMOREPLICATION_API ADemoReplicationGameState : public AGameStateBase
{
	GENERATED_BODY()
	
protected:

	virtual void BeginPlay() override;
};
