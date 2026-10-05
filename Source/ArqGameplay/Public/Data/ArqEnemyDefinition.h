#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/StreamableManager.h"
#include "ArqEnemyDefinition.generated.h"

// PrimaryDataAsset: Primary Asset Id automático + soporte de asset bundles.
// El Asset Manager lo escanea, lista y carga sin que nadie mantenga una
// lista a mano (ver DefaultGame.ini). Ver tema 8-9.
UCLASS(BlueprintType)
class ARQGAMEPLAY_API UArqEnemyDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	// --- Estadísticas (tema 8) ---
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Arq")
	float VidaMaxima = 100.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Arq")
	float DanoContacto = 10.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Arq")
	float VelocidadMovimiento = 400.f;

	// --- Composición (tema 8) ---
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Arq")
	bool bEsVolador = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Arq")
	bool bEsExplosivo = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Arq")
	bool bAtacaADistancia = false;

	// --- Referencias (tema 9): dura a propósito, para comparar con la blanda ---
	UPROPERTY(EditDefaultsOnly, Category = "Arq|Referencias")
	TObjectPtr<UStaticMesh> MeshHard;

	UPROPERTY(EditDefaultsOnly, Category = "Arq|Referencias")
	TSoftObjectPtr<UStaticMesh> MeshSoft;

	UFUNCTION(BlueprintCallable, Category = "Arq")
	void CargarMeshAsync();

	virtual FPrimaryAssetId GetPrimaryAssetId() const override;
};
