#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ArqHUDWidget.generated.h"

// El HUD no conoce el juego — solo recibe números por delegate/evento.
// Nunca castea a AArqCharacter ni incluye nada de ArqGameplay (tema 7
// y tema 10 combinados: la regla de desacoplo, ahora imposible de saltar
// por accidente porque ArqUI ni siquiera puede incluir esos headers).
UCLASS()
class ARQUI_API UArqHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Arq")
	void ActualizarEnemigosRestantes(int32 Restantes);

	UFUNCTION(BlueprintCallable, Category = "Arq")
	void ActualizarVida(float VidaActual, float VidaMaxima);
};
