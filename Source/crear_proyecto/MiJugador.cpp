// Fill out your copyright notice in the Description page of Project Settings.


#include "MiJugador.h"


//incluida  para los moviminetos 
#include"GameFramework/CharacterMovementComponent.h"

// constructor 
AMiJugador::AMiJugador()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


//	//objetivo bloqueado es igual a falso 
//	TargetLocked = false;
//	// el siguinete Ataque tambien sera falso 
//	NextAttackReady = false;
//// estan atacando igualmnete falso
//	Attacking = false;
//	// si ataca dañando tambien falso 
//	AttacDamaging = false;
//	// avanzar sera falsse 
//	MovingForward = false;
//	// retroceder es igual fasle 
//	MovingBackwards = false;
//
//	// rotar al objetio eso si sera verdadero 
//	RotateTowardsTarget = true,
//		// algun tropiezo ssera falso
//		Stumbling = false,
//		//la rotacion basica es o sera  5
//		RotationSmoothing = 5.0f;
//		// la velocida de rotacion sera 0
//		LastRotationSpeed = 0.0f;
//	
//		// son todas la variables que creamos en el archivo .h 
//		// esto lo heredara el enemigo en la clase enemiga 


}

// Called when the game starts or when spawned
void AMiJugador::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMiJugador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//// preguntamos si gira hacia el objetivo 

	//if (RotateTowardsTarget)
	//	// entonces llamamos mirar sueve 
	//	LookAtSmooth();
	//// mira hacia el objetivo 
}

////reemplaza a la funcionalidad de input 
void AMiJugador::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//CODIGO QUE NO USAREMOS´POR EL MOMENTO 
	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("forward", this, &AMiJugador::moveforward);
	PlayerInputComponent->BindAxis("derecha", this, &AMiJugador::movederecha);
	PlayerInputComponent->BindAxis("atras", this, &AMiJugador::moveatras);
	PlayerInputComponent->BindAxis("izquierda", this, &AMiJugador::moveizquierda);
	// giros 
	PlayerInputComponent->BindAxis("yaw", this, &AMiJugador::yaw);
	PlayerInputComponent->BindAxis("pitch", this, &AMiJugador::pitch);
	

}
//
//
//
//
//
//
//
//void AMiJugador::Attack()
//{
//
//	//decimos que atacar es igual a verdadero  cuando se llama a la funcion atacar 
//
//	Attacking = true;
//	NextAttackReady = false;// seguira falso 
//	AttacDamaging = false;// atacar dañando seguira falso 
//
//	// deciomos atacar al los actores vacios 
//
//	AttackHitActors.Empty();
//
//	//AQUI ES DONDE VAMOS A ALMACENAR LOS ACTORES QUE GOLPEAMOS 
//
//
//}
//
//void AMiJugador::AttackLunge()// LANZAR ATAQUE 
//{
//	//preguntamos si el objetivo no es igual  a nulo 
//	if (Target != NULL)
//	{
//
//		//variable vector QUE ES igual al objetivo, obtenemos la unbicacion del objetivo, restamos la unbiacion del actor 
//		FVector Diraection = Target->GetActorLocation() - GetActorLocation();
//		// decimo que la direccion va a ser igual al vector dado 
//		Diraection = FVector(Diraection.X, Diraection.Y, 0);
//		//matrix de rotacion ... nos dara la rotacion hacia el jugador
//		FRotator Rotacion = FRotationMatrix::MakeFromX(Diraection).Rotator();
//		// configuara la rotacion del actor aqui pasmos la rotacion del actor 
//		SetActorRotation(Rotacion);
//
//	}
//	//teletransportmos al actor haca adelante 
//	FVector nueva_ubicacion = GetActorLocation() + (GetActorForwardVector() * 70);// es propulsar el actor hacia adelante 
//	
//	SetActorLocation(nueva_ubicacion,true);
//
//
//
//}
//
//void AMiJugador::EndAttack()
//{
//	// esta funcion solo finaliza el ataque por ende las variables atacar y siguiente ataque seran false 
//	Attacking = false;
//	NextAttackReady = false;
//
//	
//}
//
//void AMiJugador::SetAttackDamaging(bool Damaging)
//{
//
//	// ataque con daño sera igual a daño que es lo qu estamos pasndo 
//	AttacDamaging = Damaging;
//}
//
//void AMiJugador::SetMiovingForward(bool IsMovingForward)
//{
//
//	// aqui decimos que avanzar es igual al parametro que estamos pasndo
//	MovingForward = IsMovingForward;
//}
//
//void AMiJugador::SetMovingBackards(bool IsMovingBackwards)
//{
//	// aqui deciomos que retroceder es igual al parametro que estamos pasnod que es retroceder 
//	MovingBackwards = IsMovingBackwards;
//
//}
//
//void AMiJugador::EndStumble()
//{
//
//	// decimos que tropezar es igual a falso
//
//	Stumbling = false;
//
//}
//
//void AMiJugador::AttackNextReady()
//{
//
//	//decimos que el proximo ataque sta listo 
//	NextAttackReady = true;
//}
//
//void AMiJugador::LookAtSmooth()
//{
//	// en mirada a la suavidad preguntamos si el obetivo no es igual a nulo y si nuestro objetivo esta bloqueado
//	// y si no estamos atacando y obtenemos el movimiento del personaje  
//	if (Target != NULL && TargetLocked && !Attacking && !GetCharacterMovement()->IsFalling())
//	{
//		// creamos un vector es igual a la direccion del objetivo, la ubicacion de actor 
//		FVector direccion = Target->GetActorLocation() - GetActorLocation();
//		direccion = FVector(direccion.X, direccion.Y, 0);
//		FRotator rotacion = FRotationMatrix::MakeFromX(direccion).Rotator();
//
//		// llamamos a rotar con suavidad 
//		FRotator rotar_suave = FMath::Lerp(GetActorRotation(), rotacion,
//			RotationSmoothing * GetWorld()->DeltaTimeSeconds);
//
//		// esta sera nuestra rotacion del personaje...
//		LastRotationSpeed = rotar_suave.Yaw - GetActorRotation().Yaw;
//
//		// establecemos la rotacion
//		SetActorRotation(rotar_suave);
//
//
//
//	}
//	
//}
//
//float AMiJugador::GetCurrentRotationSpeed()//reatcionobtener actual 
//
//{
//	//preguntamos si gira hacia el objetivo
//	if (RotateTowardsTarget)
//	{
//		// entoces va adevolver la ultima velocidad de rotacion
//		return LastRotationSpeed;
//	}
//	//por false devolvera 0 
//	return 0.0f;
//}
//
//














 ///FUNCIONES QUE NO USAREMOS POR AHORA 
void AMiJugador::moveforward(float amount)
{
	// no entrar en el cuerpo de esta funcion si controle no 
	//este configurado aun, o si la cantidad a mover es igual a 0

	if (Controller && amount)
	{
		FVector fwd = GetActorForwardVector();
		//llamamos addMovementInput a mover realmente al 
		// jugador por amount en la direccion "fwd"
		AddMovementInput(fwd, amount);
	}
}

void AMiJugador::movederecha(float amount)
{
	if (Controller && amount)
	{
		FVector derecha = GetActorRightVector();
	
		AddMovementInput(derecha, amount);
	}


}

void AMiJugador::moveizquierda(float amount)
{
	if (Controller && amount)
	{
		FVector izquierda = -GetActorRightVector();

		AddMovementInput(izquierda, amount);
	}

}

void AMiJugador::moveatras(float amount)
{
	if (Controller && amount)
	{
		FVector atras = -GetActorForwardVector();

		AddMovementInput(atras, amount);
	}


}
void AMiJugador::yaw(float amount)
{
	AddControllerYawInput(100.f * amount * GetWorld()->GetDeltaSeconds());
}
void AMiJugador::pitch(float amount)
{
	AddControllerPitchInput(100.f * amount * GetWorld()->GetDeltaSeconds());
}