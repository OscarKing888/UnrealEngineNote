// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoGameInstance.h"
#include "DemoReplication.h"

UDemoGameInstance::UDemoGameInstance()
{
	DemoLog(this, TEXT("[Init][UDemoGameInstance::Ctor]"));

}

void UDemoGameInstance::FinishDestroy()
{
	DemoLog(this, TEXT("[Init][UDemoGameInstance::FinishDestroy]"));
	
	Super::FinishDestroy();
}

void UDemoGameInstance::Init()
{
	DemoLog(this, TEXT("[Init][UDemoGameInstance::Init]"));

	Super::Init();

}

void UDemoGameInstance::StartGameInstance()
{
	DemoLog(this, TEXT("[Init][UDemoGameInstance::StartGameInstance]"));

	Super::StartGameInstance();

	g_Authority = TEXT("N/A");
}
