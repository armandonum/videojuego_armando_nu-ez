// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "paddle_player_controler.generated.h"


class ABall;
/**
 * 
 */
UCLASS()
class CREAR_PROYECTO_API Apaddle_player_controler : public APlayerController
{
	GENERATED_BODY()

		Apaddle_player_controler();

	UFUNCTION()
		virtual void SetupInputComponent() override;

protected:
	virtual void BeginPlay() override;
	

	// referencias a ball

	void Launch();
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall> BallObj;
	ABall* MyBall;

	FVector SpawnLocation = FVector(9680.0f, -5240.0f, -1050.0f);
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;

public:

	void SpawnNewBall();
	
};
