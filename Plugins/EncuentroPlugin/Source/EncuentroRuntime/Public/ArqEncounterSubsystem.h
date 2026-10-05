#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ArqEncounterSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FArqOnEnemigosRestantesCambiado, int32, Restantes);

// WorldSubsystem: vive UN NIVEL cargado — coordinación propia de ese nivel.
// Nadie lo coloca, nadie lo destruye. Ver tema 6.
//
// Extraído a feature plugin en el tema 11: autocontenido, sin ninguna
// referencia hacia ArqGameplay ni hacia el contenido del juego — la prueba
// de que esto es cierto es que compila como plugin independiente.
UCLASS()
class ENCUENTRORUNTIME_API UArqEncounterSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "Arq")
	FArqOnEnemigosRestantesCambiado OnEnemigosRestantesCambiado;

	UFUNCTION(BlueprintCallable, Category = "Arq")
	void RegistrarEnemigo(AActor* Enemigo);

	UFUNCTION(BlueprintCallable, Category = "Arq")
	void NotificarEnemigoEliminado(AActor* Enemigo);

	UFUNCTION(BlueprintPure, Category = "Arq")
	int32 GetEnemigosRestantes() const { return EnemigosActivos.Num(); }

private:
	UPROPERTY()
	TArray<TObjectPtr<AActor>> EnemigosActivos;
};
