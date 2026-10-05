using UnrealBuildTool;

public class EncuentroRuntime : ModuleRules
{
	public EncuentroRuntime(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core", "CoreUObject", "Engine"
			// Nunca "ArqGameplay": el plugin no puede referenciar al juego — tema 11.
		});
	}
}
