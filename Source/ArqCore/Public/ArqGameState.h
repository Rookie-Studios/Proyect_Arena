#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ArqGameState.generated.h"

// Tiempo de vida: UN NIVEL, EN TODAS LAS MÁQUINAS. Se replica a todos los
// clientes — es la vía oficial para que sepan lo que necesitan saber de la
// partida. Ver tema 2 y tema 14.
UCLASS()
class ARQCORE_API AArqGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY(ReplicatedUsing = OnRep_OleadaActual, BlueprintReadOnly, Category = "Arq")
	int32 OleadaActual = 0;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	void OnRep_OleadaActual();
};
