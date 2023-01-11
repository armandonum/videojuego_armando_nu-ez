// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MiJugador.generated.h"

UCLASS()
class CREAR_PROYECTO_API AMiJugador : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMiJugador();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// son las declaraciones de funcioones miembro nuevas
	// son las que permiten mover a nuestro jugador 



	 //funciones de movimiento que no usaremos 
	void moveforward(float amount);
	void movederecha(float amount);
	void moveatras(float amount);
	void moveizquierda(float amount);
	// funciones para los giros 
	void yaw(float amount);
	void pitch(float amount);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// aqui utilizaremos el patron state

	//AActor* Target;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	//	// creamos una variable bool 
	//	bool TargetLocked;


	//bool Attacking;// variable para la accion de atacar 
	//bool AttacDamaging; // daños de los ataques 
	//bool MovingForward;// variable para moverse adelante 
	//bool MovingBackwards;// variable boleana par moverse para atras 
	//bool NextAttackReady;
	//bool Stumbling;// tropiezos 

	//bool RotateTowardsTarget; // variable para dirigir la vista de nuestro jugador

	//UPROPERTY(EditAnywhere, Category = "Animation")// creamos una propiedad editable en blueprint de nombre animacion 
	//	float RotationSmoothing;

	//UPROPERTY(EditAnywhere, Category = "Animations")// propiedad editable animaciones para tropiezos (se ejecuatan cuando recibamos daño
	//	TArray<UAnimMontage*>AttackAnimations; // es un contenedor


	//UPROPERTY(EditAnywhere, Category = "Animations") // segunda propiedad editabel animaciones 
	//	TArray<UAnimMontage*>TakeHit_StumbleBackwards;



	//// racion de los ataauqes de otros actoere 

	//TArray<AActor*>AttackHitActors;

	////cramos una funcion virtual para en el cuerpo implementeos el ataque de nustro jugador 

	//virtual void Attack();
	//UFUNCTION(BlueprintCallable, Category = "Combat")
	//	virtual void AttackLunge();// funcion para lanzar ataque 


	//UFUNCTION(BlueprintCallable, Category = "Combat")
	//	virtual void EndAttack();// finalizar ataque 

	//UFUNCTION(BlueprintCallable, Category = "Combat")
	//	virtual void SetAttackDamaging(bool Damaging);

	//// animacion al moverse adekante 
	//UFUNCTION(BlueprintCallable, Category = "Animation")
	//	virtual void SetMiovingForward(bool IsMovingForward);

	//UFUNCTION(BlueprintCallable, Category = "Animation")
	//	virtual void SetMovingBackards(bool IsMovingBackwards);

	//UFUNCTION(BlueprintCallable, Category = "Animation")
	//	virtual void EndStumble();

	//
	//UFUNCTION(BlueprintCallable, Category = "Combat")// propeidad decombate editable 
	//	virtual void AttackNextReady();

	////TODAS LAS FUNCIONES ANTERIORES CREAN BLUEPRINTS INVOCABLES 

	//virtual void LookAtSmooth();

	//// animacion para la rotacion 

	//UFUNCTION(BlueprintCallable, Category = "Animation")
	//	float GetCurrentRotationSpeed();

	//float LastRotationSpeed;


	
};
