// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogDemoReplication, Log, All);


extern FString LogTag;
extern class APlayerState* g_PlayerState;

void DemoLog(const TCHAR* Fmt, ...);