#include "ArqGameMode.h"
#include "ArqGameState.h"

AArqGameMode::AArqGameMode()
{
	GameStateClass = AArqGameState::StaticClass();
}

void AArqGameMode::IniciarSiguienteOleada()
{
	if (AArqGameState* GS = GetGameState<AArqGameState>())
	{
		GS->OleadaActual += 1;
	}
}
