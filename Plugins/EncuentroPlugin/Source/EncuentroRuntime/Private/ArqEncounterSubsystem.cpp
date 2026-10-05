#include "ArqEncounterSubsystem.h"

void UArqEncounterSubsystem::RegistrarEnemigo(AActor* Enemigo)
{
	if (!Enemigo)
	{
		return;
	}
	EnemigosActivos.AddUnique(Enemigo);
	OnEnemigosRestantesCambiado.Broadcast(EnemigosActivos.Num());
}

void UArqEncounterSubsystem::NotificarEnemigoEliminado(AActor* Enemigo)
{
	EnemigosActivos.RemoveSingleSwap(Enemigo);
	OnEnemigosRestantesCambiado.Broadcast(EnemigosActivos.Num());
}
