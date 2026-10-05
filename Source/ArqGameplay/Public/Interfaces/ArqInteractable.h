#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ArqInteractable.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UArqInteractable : public UInterface
{
	GENERATED_BODY()
};

// Interfaz de pura notificación — comparativa con IArqDamageable en tema 7:
// esta no espera ningún dato de vuelta, solo avisa.
class ARQGAMEPLAY_API IArqInteractable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category = "Arq")
	void AlInteractuar(AActor* Instigador);
};
