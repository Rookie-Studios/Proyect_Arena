#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ArqCharacter.generated.h"

// Clase base en C++. Los tres modos de exponer a Blueprint, uno de cada,
// a propósito — ver tema 3.
UCLASS()
class ARQGAMEPLAY_API AArqCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AArqCharacter();

	// BlueprintCallable: C++ implementa, BP invoca.
	UFUNCTION(BlueprintCallable, Category = "Arq")
	void AplicarDano(float Cantidad, AActor* Instigador);

	// BlueprintImplementableEvent: C++ avisa, BP decide. Sin cuerpo en C++.
	UFUNCTION(BlueprintImplementableEvent, Category = "Arq")
	void AlRecibirDano(float Cantidad);

	// BlueprintNativeEvent: C++ por defecto, BP puede sustituirlo.
	UFUNCTION(BlueprintNativeEvent, Category = "Arq")
	void AlMorir();
	virtual void AlMorir_Implementation();

protected:
	// RPC: el cliente PIDE, nunca decide. Ver tema 14.
	UFUNCTION(Server, Reliable)
	void ServerAplicarDano(float Cantidad, AActor* Instigador);
};
