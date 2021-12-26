// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DemoGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class DEMOREPLICATION_API UDemoGameInstance : public UGameInstance
{
	GENERATED_BODY()

protected:

public:

	UDemoGameInstance();

	virtual void FinishDestroy() override;

	virtual void Init() override;
	virtual void StartGameInstance() override;

	
};
