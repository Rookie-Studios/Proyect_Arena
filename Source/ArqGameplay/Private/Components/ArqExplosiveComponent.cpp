#include "Components/ArqExplosiveComponent.h"
#include "Interfaces/ArqDamageable.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

void UArqExplosiveComponent::Detonar()
{
	AActor* Owner = GetOwner();
	if (!Owner || !Owner->HasAuthority())
	{
		return;   // la explosión, como cualquier daño, la decide el servidor — tema 14
	}

	TArray<FOverlapResult> Resultados;
	FCollisionShape Esfera = FCollisionShape::MakeSphere(RadioExplosion);
	Owner->GetWorld()->OverlapMultiByObjectType(
		Resultados, Owner->GetActorLocation(), FQuat::Identity,
		FCollisionObjectQueryParams(ECC_Pawn), Esfera);

	for (const FOverlapResult& R : Resultados)
	{
		if (AActor* Otro = R.GetActor())
		{
			if (Otro->Implements<UArqDamageable>())
			{
				IArqDamageable::Execute_RecibirDano(Otro, DanoExplosion, Owner);
			}
		}
	}
}
