// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoReplicationGameState.h"
#include "DemoReplication.h"



ADemoReplicationGameState::ADemoReplicationGameState()
{
	DemoLog(this, TEXT("[Init][ADemoReplicationGameState::Ctor]"));
}


void ADemoReplicationGameState::BeginPlay()
{
	if (this->HasAuthority())
	{
		g_Authority = TEXT("GameState[服务器]");
	}
	else
	{
		g_Authority = TEXT("GameState[客户端]");
	}

	DemoLog(this, TEXT("[Init][ADemoReplicationGameState::BeginPlay]"));

	// 重载函数一定要调用底层，不管有没有功能，养成习惯免得漏掉
	Super::BeginPlay();
}

void ADemoReplicationGameState::Destroyed()
{
	DemoLog(this, TEXT("[Init][ADemoReplicationGameState::Destroyed]"));

	// 重载函数一定要调用底层，不管有没有功能，养成习惯免得漏掉
	Super::Destroyed();
}
