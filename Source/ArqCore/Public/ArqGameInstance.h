#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ArqGameInstance.generated.h"

// Tiempo de vida: TODA la sesión de juego. Ver tema 2.
// AQUI VA: datos que sobreviven al cambio de nivel (progreso persistente,
// ajustes elegidos en el frontend, estado de la cuenta).
// AQUI NO VA: nada específico de una partida en curso — eso es GameState.
UCLASS()
class ARQCORE_API UArqGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
};
