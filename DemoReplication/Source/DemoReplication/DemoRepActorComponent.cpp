// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoRepActorComponent.h"
#include "DemoReplication.h"

// Sets default values for this component's properties
UDemoRepActorComponent::UDemoRepActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	DemoLog(this, TEXT("[Init][UDemoRepActorComponent::Ctor]"));
	// ...
}


// Called when the game starts
void UDemoRepActorComponent::BeginPlay()
{
	DemoLog(this, TEXT("[Init][UDemoRepActorComponent::BeginPlay]"));

	Super::BeginPlay();

	// ...
	
}


void UDemoRepActorComponent::FinishDestroy()
{
	DemoLog(this, TEXT("[Init][UDemoRepActorComponent::FinishDestroy]"));
	Super::FinishDestroy();
}

// Called every frame
void UDemoRepActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

