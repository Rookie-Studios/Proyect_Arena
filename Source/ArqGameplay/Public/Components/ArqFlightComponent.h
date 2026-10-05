#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ArqFlightComponent.generated.h"

// Característica cruzada #1 (tema 4-5): un enemigo puede llevar este
// componente o no, independientemente de los demás.
UCLASS(ClassGroup = (Arq), meta = (BlueprintSpawnableComponent))
class ARQGAMEPLAY_API UArqFlightComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Arq")
	float AlturaCrucero = 300.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Arq")
	float VelocidadAscenso = 150.f;
};
