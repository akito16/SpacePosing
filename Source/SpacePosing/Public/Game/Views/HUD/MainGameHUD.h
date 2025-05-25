// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Game/Views/TitleMenuWidget.h"
#include "MainGameHUD.generated.h"

/**
 * ÉÅÉCÉìHUD
 */
UCLASS()
class SPACEPOSING_API AMainGameHUD : public AHUD
{
	GENERATED_BODY()
	
private:
	AMainGameHUD();

	TSubclassOf<UTitleMenuWidget> _titleMenuWidgetSubclass;
	UTitleMenuWidget* _titleMenuWidget;

public:
	void SetupTitle(TFunction<void()> onStartGame, TFunction<void()> onQuitGame);
};
