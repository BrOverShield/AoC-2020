// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AoC : ModuleRules
{
	public AoC(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
