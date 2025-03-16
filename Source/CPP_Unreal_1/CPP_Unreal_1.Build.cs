// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CPP_Unreal_1 : ModuleRules
{
	public CPP_Unreal_1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
