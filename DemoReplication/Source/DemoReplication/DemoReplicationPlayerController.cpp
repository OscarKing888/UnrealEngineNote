// Copyright Epic Games, Inc. All Rights Reserved.

#include "DemoReplicationPlayerController.h"
#include "DemoReplication.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "DemoReplicationCharacter.h"
#include "Engine/World.h"

ADemoReplicationPlayerController::ADemoReplicationPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;


	DemoLog(this, TEXT("[Init][ADemoReplicationPlayerController::Ctor]"));
}

void ADemoReplicationPlayerController::BeginPlay()
{
	DemoLog(this, TEXT("[Init][ADemoReplicationPlayerController::BeginPlay]"));

	// 重载函数一定要调用底层，不管有没有功能，养成习惯免得漏掉
	Super::BeginPlay();
}

void ADemoReplicationPlayerController::Destroyed()
{
	DemoLog(this, TEXT("[Init][ADemoReplicationPlayerController::Destroyed]"));

	// 重载函数一定要调用底层，不管有没有功能，养成习惯免得漏掉
	Super::Destroyed();
}

void ADemoReplicationPlayerController::ClientFun_Implementation()
{
	DemoLog(this, TEXT("[RPC][ADemoReplicationPlayerController::ClientFun_Implementation]在客户端调用"));
}

void ADemoReplicationPlayerController::ServerFun_Implementation()
{
	DemoLog(this, TEXT("[RPC][ADemoReplicationPlayerController::ClientFun_Implementation] 在服务器调用"));
}

void ADemoReplicationPlayerController::ServerAndClientFun_Implementation()
{
	DemoLog(this, TEXT("[RPC][ADemoReplicationPlayerController::ClientFun_Implementation] 在客户端和服务器调用"));
}

void ADemoReplicationPlayerController::BP_DemoFunction()
{
	DemoLog(this, TEXT("[BP][ADemoReplicationPlayerController::BP_DemoFunction] 演示蓝图调用函数"));
}

void ADemoReplicationPlayerController::BP_DemoNativeEvent_Implementation()
{
	DemoLog(this, TEXT("[BP][ADemoReplicationPlayerController::BP_DemoNativeEvent_Implementation] 演示Native事件"));
}

void ADemoReplicationPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}
}

void ADemoReplicationPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ADemoReplicationPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &ADemoReplicationPlayerController::OnSetDestinationReleased);

	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ADemoReplicationPlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &ADemoReplicationPlayerController::MoveToTouchLocation);

	InputComponent->BindAction("ResetVR", IE_Pressed, this, &ADemoReplicationPlayerController::OnResetVR);

}

void ADemoReplicationPlayerController::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ADemoReplicationPlayerController::MoveToMouseCursor()
{
	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		if (ADemoReplicationCharacter* MyPawn = Cast<ADemoReplicationCharacter>(GetPawn()))
		{
			if (MyPawn->GetCursorToWorld())
			{
				UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, MyPawn->GetCursorToWorld()->GetComponentLocation());
			}
		}
	}
	else
	{
		// Trace to see what is under the mouse cursor
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);

		if (Hit.bBlockingHit)
		{
			// We hit something, move there
			SetNewMoveDestination(Hit.ImpactPoint);
		}
	}
}

void ADemoReplicationPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void ADemoReplicationPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void ADemoReplicationPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void ADemoReplicationPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}
