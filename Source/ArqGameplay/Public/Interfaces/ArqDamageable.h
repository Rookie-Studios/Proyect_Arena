#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ArqDamageable.generated.h"

// UInterface: clase vacía, solo para el sistema de reflexión. Ver tema 7.
UINTERFACE(MinimalAPI, BlueprintType)
class UArqDamageable : public UInterface
{
	GENERATED_BODY()
};

// IArqDamageable: la interfaz real. Toda la lógica va aquí.
// Sustituye al cast directo: "¿puede recibir daño?" en vez de "¿es un AArqCharacter?".
class ARQGAMEPLAY_API IArqDamageable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category = "Arq")
	void RecibirDano(float Cantidad, AActor* Instigador);
};
