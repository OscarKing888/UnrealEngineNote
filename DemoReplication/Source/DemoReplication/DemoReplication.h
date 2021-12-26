// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(Demo, Log, All);


extern FString g_Authority;
extern class APlayerState* g_PlayerState;

void DemoLog(UObject* Context, const TCHAR* Fmt, ...);