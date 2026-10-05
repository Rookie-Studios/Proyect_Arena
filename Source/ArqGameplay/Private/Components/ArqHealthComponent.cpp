#include "Components/ArqHealthComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/Actor.h"

UArqHealthComponent::UArqHealthComponent()
{
	// El componente se replica — necesario para que VidaActual llegue a los clientes.
	SetIsReplicatedByDefault(true);
}

void UArqHealthComponent::RecibirDano_Implementation(float Cantidad, AActor* Instigador)
{
	// La comprobación de autoridad vive en quien LLAMA a este componente
	// (ver AArqCharacter::AplicarDano) — pero una segunda comprobación
	// aquí es barata y evita que una ruta nueva se cuele sin pasar por ahí.
	if (GetOwner() && !GetOwner()->HasAuthority())
	{
		return;
	}

	VidaActual = FMath::Clamp(VidaActual - Cantidad, 0.f, VidaMaxima);

	// El componente NO decide el feedback visual — solo emite el evento.
	// La lógica de vida y la de presentación no tienen por qué conocerse. Ver tema 7.
	OnDanoRecibido.Broadcast(Cantidad, Instigador);

	if (VidaActual <= 0.f)
	{
		OnMuerte.Broadcast();
	}
}

void UArqHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UArqHealthComponent, VidaActual);
}

void UArqHealthComponent::OnRep_VidaActual()
{
	// Se ejecuta en CADA CLIENTE automáticamente cuando el valor cambia en
	// el servidor. Aquí es donde engancharíais una barra de vida en el HUD
	// (ArqUI), siempre por delegate — nunca con ArqUI incluyendo este header.
}
