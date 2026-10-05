using UnrealBuildTool;

public class ArqUI : ModuleRules
{
	public ArqUI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core", "CoreUObject", "Engine", "UMG", "ArqCore"
			// Nunca "ArqGameplay" — esta línea es, literalmente, la regla
			// del tema 10 escrita en código: el compilador la impone.
		});
	}
}
