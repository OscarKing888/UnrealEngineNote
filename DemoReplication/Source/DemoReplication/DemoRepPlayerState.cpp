// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoRepPlayerState.h"
#include "DemoReplication.h"

void ADemoRepPlayerState::BeginPlay()
{
	// 重载函数一定要调用底层，不管有没有功能，养成习惯免得漏掉
	Super::BeginPlay();

	g_PlayerState = this;

	DemoLog(TEXT("[ADemoRepPlayerState::BeginPlay]"));
}

void ADemoRepPlayerState::Destroyed()
{
	// 重载函数一定要调用底层，不管有没有功能，养成习惯免得漏掉
	Super::Destroyed();

	g_PlayerState = nullptr;
}

void ADemoRepPlayerState::OnRep_PlayerName()
{
	// 重载函数一定要调用底层，不管有没有功能，养成习惯免得漏掉
	Super::OnRep_PlayerName();

	DemoLog(TEXT("[ADemoRepPlayerState::OnRep_PlayerName] %s"), *GetPlayerName());
}

void ADemoRepPlayerState::OnRep_PlayerId()
{
	// 重载函数一定要调用底层，不管有没有功能，养成习惯免得漏掉
	Super::OnRep_PlayerId();

	DemoLog(TEXT("[ADemoRepPlayerState::OnRep_PlayerId] %d"), GetPlayerId());
}

void ADemoRepPlayerState::OnRep_UniqueId()
{
	// 重载函数一定要调用底层，不管有没有功能，养成习惯免得漏掉
	Super::OnRep_UniqueId();

	DemoLog(TEXT("[ADemoRepPlayerState::OnRep_UniqueId] %s"), *GetUniqueId().ToString());
}

void ADemoRepPlayerState::OnRep_bIsInactive()
{
	// 重载函数一定要调用底层，不管有没有功能，养成习惯免得漏掉
	Super::OnRep_bIsInactive();

	DemoLog(TEXT("[ADemoRepPlayerState::OnRep_bIsInactive] %d"), GetPlayerId());
}

void ADemoRepPlayerState::OnRep_Score()
{
	// 重载函数一定要调用底层，不管有没有功能，养成习惯免得漏掉
	Super::OnRep_Score();

	DemoLog(TEXT("[ADemoRepPlayerState::OnRep_Score] %f"), GetScore());
}
