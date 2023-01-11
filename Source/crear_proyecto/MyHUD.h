// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/Canvas.h"
#include"Engine/Font.h"
#include"MiJugador.h"


#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

struct Message
{
	FString message;
	float time;
	FColor color;
	UTexture2D* tex;


	Message()
	{
		// configurar el tiempo determinado 
		time = 5.f;
		color=FColor::White;
		tex =nullptr;
	}
	Message(FString iMessage, float iTime, FColor iColor, UTexture2D* iTexture)
	{
		message = iMessage;
		time = iTime;
		color = iColor;
		tex = iTexture;
	}
};

struct Icon
{
	FString name;
	UTexture2D* tex;
	Icon()
	{
		name = "UNKNOWN ICON"; tex = nullptr;
		
	}
	Icon(FString& iName, UTexture2D* iTex)
	{
		name = iName;
		tex = iTex;
	}
};

/**
 * 
 */
UCLASS()
class CREAR_PROYECTO_API AMyHUD : public AHUD
{
	GENERATED_BODY()
public:
	// la funte usada para renderizar el texto en el HUD
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont)
		UFont* hudFont;
	// un array de mensajes que mostrar 
	TArray<Message> messages;
	
		FVector2D dimensions;
	virtual void DrawHUD() override;
	void DrawMessages();

	//una funcion que nos permita añadir un mensaje que mostrar
	void addMessage(Message msg);

protected:
	virtual void BeginPlay() override;

private:
	int32 sizeX;
	bool doOnce = false;
	
};
