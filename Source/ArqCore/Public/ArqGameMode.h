#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ArqGameMode.generated.h"

// Tiempo de vida: UN NIVEL, SOLO CON AUTORIDAD. Existe únicamente en el
// servidor y NUNCA se replica a los clientes — ver tema 2 y tema 14.
// AQUI VA: reglas del juego que un cliente no debe poder inspeccionar
// (condiciones de victoria, parámetros de dificultad del servidor).
UCLASS()
class ARQCORE_API AArqGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AArqGameMode();

	// Pedir el inicio de una oleada. Siempre se llama con autoridad porque
	// GameMode solo existe en el servidor — no hace falta comprobar
	// HasAuthority() aquí, pero SÍ hay que comprobarlo en cualquier función
	// de AArqCharacter o de un componente que pueda ser llamada por error
	// desde un contexto sin autoridad (ver ArqHealthComponent).
	UFUNCTION(BlueprintCallable, Category = "Arq")
	void IniciarSiguienteOleada();
};
