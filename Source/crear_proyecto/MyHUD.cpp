// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"

void AMyHUD::DrawHUD()

{
// llamar priero a la funcion de la supercasle 	
	Super::DrawHUD();
sizeX = Canvas->SizeX;

const FVector2D viewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
dimensions.X = viewportSize.X;
dimensions.Y = viewportSize.Y;

DrawMessages();

}

	
	



	void AMyHUD::DrawMessages()
	{
		// nos movemos de atras a adelante a traves de la lista asi si eliminamos 
	// in item mientras nos iteramos no sera ningun problema
		for (int c = messages.Num() - 1; c >= 0; c--)
		{
			// dibujamos la caja de fondo con el tamaño adecuado 
			// para el mensaje 
			float outputWidth, outputHeight, pad = 10.0f;
			GetTextSize(messages[c].message, outputWidth, outputHeight, hudFont, 1.0f);

			float messageH = outputHeight + 2.0f * pad;
			float x = 0.0f, y = c * messageH;
			// fondo negro 
			DrawRect(FLinearColor::Transparent, x, y, Canvas->SizeX, messageH);

			// dibujar textura 
			DrawTexture(messages[c].tex, x, y, messageH, messageH, 0, 0, 1, 1);

			// dibujamos nuestro mensaje usando hudFont 
			DrawText(messages[c].message, messages[c].color, x + pad+ messageH, y + pad, hudFont);


			// reducimos el timepo de vida en el tiempo que paso desde el ultimo fotograma
			messages[c].time -= GetWorld()->GetDeltaSeconds();

			// cuando se supere el timpo del mensaje lo eliminamos 
			if (messages[c].time < 0)
			{
				messages.RemoveAt(c);
			}

		}

	}


void AMyHUD::addMessage(Message msg)
{
	messages.Add(msg);
}

void AMyHUD::BeginPlay()
{
}


