#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/ArqDamageable.h"
#include "ArqHealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FArqOnDanoRecibido, float, Cantidad, AActor*, Instigador);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FArqOnMuerte);

// ActorComponent puro — sin posición ni representación visual. Ver tema 5.
// Ampliado en tema 14 con replicación: la vida es el ejemplo canónico de
// "dato que todos los clientes necesitan conocer, pero solo el servidor
// puede cambiar".
UCLASS(ClassGroup = (Arq), meta = (BlueprintSpawnableComponent))
class ARQGAMEPLAY_API UArqHealthComponent : public UActorComponent, public IArqDamageable
{
	GENERATED_BODY()

public:
	UArqHealthComponent();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Arq")
	float VidaMaxima = 100.f;

	// Replicada con notificación: cada cliente se entera del cambio
	// automáticamente a través de OnRep_VidaActual. Ver tema 14.
	UPROPERTY(ReplicatedUsing = OnRep_VidaActual, BlueprintReadOnly, Category = "Arq")
	float VidaActual = 100.f;

	UPROPERTY(BlueprintAssignable, Category = "Arq")
	FArqOnDanoRecibido OnDanoRecibido;

	UPROPERTY(BlueprintAssignable, Category = "Arq")
	FArqOnMuerte OnMuerte;

	virtual void RecibirDano_Implementation(float Cantidad, AActor* Instigador) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	void OnRep_VidaActual();
};
