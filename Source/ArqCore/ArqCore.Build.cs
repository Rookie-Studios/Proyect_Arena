using UnrealBuildTool;

public class ArqCore : ModuleRules
{
	public ArqCore(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core", "CoreUObject", "Engine"   // se ven también desde fuera
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}
