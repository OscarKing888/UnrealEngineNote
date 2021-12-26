// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DemoRepActor.generated.h"

UCLASS(Blueprintable, BlueprintType)
class DEMOREPLICATION_API ADemoRepActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADemoRepActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing=OnRep_DemoReplicateIntValue, Category=Gameplay)
	int DemoReplicateIntValue;

	UFUNCTION()
	void OnRep_DemoReplicateIntValue();

	UFUNCTION(BlueprintCallable)
	void ModifyDemoValue(int Val);

};
