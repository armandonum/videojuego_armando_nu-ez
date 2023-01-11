// Copyright Epic Games, Inc. All Rights Reserved.


#include "crear_proyectoGameModeBase.h"



void Acrear_proyectoGameModeBase::StartPlay()
{Super::StartPlay();
	if (GEngine)
	{
		// muestra un mensaje de depuracion durante 5 segundos 
		// el valor "key" -1 (primer argumento) indica que no tendra que actualizar este mensaje nunca 
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("tu historia empieza ahora "));
	}
}
