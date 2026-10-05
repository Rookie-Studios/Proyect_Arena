#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ArqGameplaySettings.generated.h"

// UDeveloperSettings: aparece en Project Settings, no en el nivel.
// Nota del check de arquitectura (Tools/check_arquitectura.py): esta clase
// está exenta de la regla "nunca referencia dura", porque sus assets son
// de configuración y se usan siempre. Razón anotada en DEUDA.md.
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Arq Gameplay"))
class ARQGAMEPLAY_API UArqGameplaySettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(config, EditAnywhere, Category = "Arq")
	int32 MaxOleadas = 10;
};
