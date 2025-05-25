// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Game/Views/Widget/TitleMenuWidget.h"
#include "Game/Views/Widget/StageSelectButtonWidget.h"
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

	TSubclassOf<UStageSelectButtonWidget> _stageSelectWidgetSubclass;
	UStageSelectButtonWidget* _stageSelectWidget;

	TFunction<void()> _onClickStart;

	void OnClickStartAction();

public:
	void SetupTitle(TFunction<void()> onStartGame, TFunction<void()> onQuitGame);
};
