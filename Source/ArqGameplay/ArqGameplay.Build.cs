using UnrealBuildTool;

public class ArqGameplay : ModuleRules
{
	public ArqGameplay(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core", "CoreUObject", "Engine", "ArqCore"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
			"GameplayTags", "EnhancedInput"   // solo se usan aquí dentro
		});
	}
}
