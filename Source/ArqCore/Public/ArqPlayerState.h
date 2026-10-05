#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "ArqPlayerState.generated.h"

// Tiempo de vida: UN JUGADOR, toda la partida — sobrevive a la muerte del Pawn.
// Es el sitio que más se olvida: si algo tiene que sobrevivir a un respawn,
// casi siempre vive aquí. Ver tema 2.
UCLASS()
class ARQCORE_API AArqPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	// Oleadas superadas por este jugador — sobrevive a cada respawn (tema 6).
	UPROPERTY(ReplicatedUsing = OnRep_OleadasSuperadas, BlueprintReadOnly, Category = "Arq")
	int32 OleadasSuperadas = 0;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	void OnRep_OleadasSuperadas();
};
