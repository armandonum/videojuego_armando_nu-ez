// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include"Components/SphereComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPC.generated.h"

UCLASS()
class CREAR_PROYECTO_API ANPC : public ACharacter
{
	GENERATED_BODY()
public:
	// la esfera con la que el jugador puede colisionar 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
		USphereComponent* ProxSphere;
	// este es el nombre del NPC
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
		FString name;

	// esta es la textura 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCMessage")
		UTexture2D* NpcFace;
	

	// este es el mensaje del NPC que dira al activarse 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
		FString NpcMessage; // el cuerpo correspondiente de esta funcion es 
	// ANPC:: Prox_Implementation, __no__ ANPC::Prox()!
	// la razon de que se escriba de este modo es por que este es un BlueprintNativeEvent
	UFUNCTION(BlueprintNativeEvent, Category = "Collision")
		void Prox(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFomSweep, const FHitResult& SweepResult);
	// esto puede que no sea nescesario a no ser que tengas un error de compilacion diciendo que no puede encontrar la funcion 
	virtual int Prox_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	// configurar los valores por defecto para las propiedades de este caracter
	ANPC(const FObjectInitializer& ObjectInitializaer);
protected:
	// llamada cuando el juego se inicia o cuando el NPC es creado 
	virtual void BeginPlay() override;
public:
	//llamada cada fotograma 
	virtual void Tick(float DeltaTime) override;
	// llamada para enlazar la funcionalidad a la entrada(input)
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
