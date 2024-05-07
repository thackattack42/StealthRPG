// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RPG_Tutorial_Series : ModuleRules
{
	public RPG_Tutorial_Series(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
