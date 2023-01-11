// Fill out your copyright notice in the Description page of Project Settings.

#include"MiJugador.h"
#include"MyHud.h"

#include "NPC.h"

// Sets default values
ANPC::ANPC(const FObjectInitializer& ObjetInitializer)
: Super(ObjetInitializer)
{
	ProxSphere = ObjetInitializer.CreateDefaultSubobject<USphereComponent>(this,
		TEXT("Proxinity Sphere"));
	ProxSphere->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	ProxSphere->SetSphereRadius(32.0f);
	//codigo para hacer que ANPC::Prox() se ejecute cuando esta esfera de proximidad se superpone con otro actor 
	ProxSphere->OnComponentBeginOverlap.AddDynamic(this, &ANPC::Prox);
	NpcMessage = "hola soy saw"; // ensaje predeterminado puede ser editado en el blueprint


}


// observa como aunque este fue declarado como ANPC::Prox() en el header qui lo es ahora como ANPC::Prox_Implementation
int  ANPC::Prox_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)


{

	// si el actor que entra en contacto no es el jugador simplemente saldremos de la funcion
	if (Cast<AMiJugador>(OtherActor) == nullptr) {
		return -1;
	}
	APlayerController* PController = GetWorld()->GetFirstPlayerController();
	if (PController)
	{
		AMyHUD* hud = Cast<AMyHUD>(PController->GetHUD());
		hud->addMessage(Message(name + static_cast<FString>(": ")+NpcMessage, 5.f, FColor::Black,NpcFace));
	}
	return 0;
}

// llamado cuando el juego empieza o el NPC es creado 
void ANPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

