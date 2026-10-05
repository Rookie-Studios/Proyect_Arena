#include "ArqPlayerState.h"
#include "Net/UnrealNetwork.h"

void AArqPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AArqPlayerState, OleadasSuperadas);
}

void AArqPlayerState::OnRep_OleadasSuperadas()
{
	// El HUD (ArqUI) escucha esto por delegate/interfaz, nunca por cast directo — tema 7.
}
