// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoRepActor.h"
#include "DemoReplication.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ADemoRepActor::ADemoRepActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

}

// Called when the game starts or when spawned
void ADemoRepActor::BeginPlay()
{
	Super::BeginPlay();

	DemoLog(TEXT("%s [ADemoRepActor::BeginPlay] DemoReplicateIntValue:%d"), *LogTag, DemoReplicateIntValue);
	
}

// Called every frame
void ADemoRepActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADemoRepActor::OnRep_DemoReplicateIntValue()
{
	DemoLog(TEXT("[ADemoRepActor::OnRep_DemoReplicateIntValue] 同步值:%d"), DemoReplicateIntValue);
}

void ADemoRepActor::ModifyDemoValue(int Val)
{
	DemoLog(TEXT("[ADemoRepActor::ModifyDemoValue] 新值:%d"), Val);
	DemoReplicateIntValue = Val;
}

void ADemoRepActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	// 千万不要忘记这行代码让父类也收集同步属性
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADemoRepActor, DemoReplicateIntValue);
}
