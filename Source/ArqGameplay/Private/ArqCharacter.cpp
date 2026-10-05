#include "ArqCharacter.h"
#include "Components/ArqHealthComponent.h"

AArqCharacter::AArqCharacter()
{
	bReplicates = true;
}

void AArqCharacter::AplicarDano(float Cantidad, AActor* Instigador)
{
	// Un cliente nunca decide el daño por sí mismo: si no tiene autoridad,
	// pide al servidor en vez de aplicar el cambio localmente. Ver tema 14.
	if (!HasAuthority())
	{
		ServerAplicarDano(Cantidad, Instigador);
		return;
	}

	if (UArqHealthComponent* Health = FindComponentByClass<UArqHealthComponent>())
	{
		Health->RecibirDano_Implementation(Cantidad, Instigador);
	}
}

void AArqCharacter::ServerAplicarDano_Implementation(float Cantidad, AActor* Instigador)
{
	// Este cuerpo SOLO se ejecuta en el servidor — el sistema de reflexión
	// de Unreal conecta la declaración con este _Implementation; nunca se
	// llama directamente desde fuera.
	AplicarDano(Cantidad, Instigador);
}

void AArqCharacter::AlMorir_Implementation()
{
	// Implementación por defecto vacía — un Blueprint hijo puede sustituirla.
}
