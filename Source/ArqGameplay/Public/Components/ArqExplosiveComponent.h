#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ArqExplosiveComponent.generated.h"

// Característica cruzada #2 (tema 4-5).
UCLASS(ClassGroup = (Arq), meta = (BlueprintSpawnableComponent))
class ARQGAMEPLAY_API UArqExplosiveComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Arq")
	float RadioExplosion = 250.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Arq")
	float DanoExplosion = 40.f;

	// Overlap por radio que llama a IArqDamageable sobre cada actor
	// encontrado — el ejercicio central del tema 5.
	UFUNCTION(BlueprintCallable, Category = "Arq")
	void Detonar();
};
