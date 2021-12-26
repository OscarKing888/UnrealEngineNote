// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoReplicationGameState.h"
#include "DemoReplication.h"


void ADemoReplicationGameState::BeginPlay()
{
	Super::BeginPlay();

	if (this->HasAuthority())
	{
		LogTag = TEXT("GameState[服务器]");
	}
	else
	{
		LogTag = TEXT("GameState[客户端]");
	}

	DemoLog(TEXT("[GameState::BeginPlay]"));

}
