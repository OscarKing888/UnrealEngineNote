// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DemoReplicationPlayerController.generated.h"

UCLASS(Blueprintable, BlueprintType)
class ADemoReplicationPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ADemoReplicationPlayerController();
	virtual void BeginPlay() override;
	virtual void Destroyed() override;

	UFUNCTION(Client, Unreliable, BlueprintCallable, Category=Demo)
	void ClientFun();

	UFUNCTION(Server, Unreliable, BlueprintCallable, Category=Demo)
	void ServerFun();

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category=Demo)
	void ServerAndClientFun();


	UFUNCTION(BlueprintCallable, Category=Demo)
	void BP_DemoFunction();

	UFUNCTION(BlueprintImplementableEvent, Category=Demo)
	void BP_DemoEvent();

	UFUNCTION(BlueprintNativeEvent, Category=Demo)
	void BP_DemoNativeEvent();

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);
	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
};


