#include "ArqGameState.h"
#include "Net/UnrealNetwork.h"

void AArqGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AArqGameState, OleadaActual);
}

void AArqGameState::OnRep_OleadaActual()
{
	// Los clientes se enteran del cambio de oleada aquí — nunca directamente
	// desde el Subsystem del servidor. Ver tema 6 y tema 14.
}
