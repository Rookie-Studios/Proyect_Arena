#include "Data/ArqEnemyDefinition.h"
#include "Engine/AssetManager.h"

FPrimaryAssetId UArqEnemyDefinition::GetPrimaryAssetId() const
{
	return FPrimaryAssetId("EnemyDefinition", GetFName());
}

void UArqEnemyDefinition::CargarMeshAsync()
{
	UAssetManager::GetStreamableManager().RequestAsyncLoad(MeshSoft.ToSoftObjectPath());
}
