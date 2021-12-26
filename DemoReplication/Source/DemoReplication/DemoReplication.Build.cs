// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DemoReplication : ModuleRules
{
	public DemoReplication(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule" });
    }
}
