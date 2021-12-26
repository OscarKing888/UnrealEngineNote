// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "DemoRepPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class DEMOREPLICATION_API ADemoRepPlayerState : public APlayerState
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Destroyed() override;
	
	virtual void OnRep_PlayerName() override;
	virtual void OnRep_PlayerId() override;		
	virtual void OnRep_UniqueId() override;
	virtual void OnRep_bIsInactive() override;
	virtual void OnRep_Score() override;

public:
	
	ADemoRepPlayerState();
};
