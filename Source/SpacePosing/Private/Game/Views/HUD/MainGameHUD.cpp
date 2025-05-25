// Fill out your copyright notice in the Description page of Project Settings.

#include "Game/Views/HUD/MainGameHUD.h"

AMainGameHUD::AMainGameHUD()
{
	static ConstructorHelpers::FClassFinder<UTitleMenuWidget> TitleMenuWidget(TEXT("/Game/Assets/Blueprints/Views/Widget/BPW_TitleMenuWidget"));
	_titleMenuWidgetSubclass = TitleMenuWidget.Class;
	static ConstructorHelpers::FClassFinder<UStageSelectButtonWidget> StageButtonMenuWidget(TEXT("/Game/Assets/Blueprints/Views/Widget/BPW_StageSelectButtonWidget"));
	_stageSelectWidgetSubclass = StageButtonMenuWidget.Class;
}

void AMainGameHUD::SetupTitle(TFunction<void()> onStartGame, TFunction<void()> onQuitGame)
{
	_onClickStart = onStartGame;
	_titleMenuWidget = CreateWidget<UTitleMenuWidget>(GetWorld(), _titleMenuWidgetSubclass);
	_titleMenuWidget->SetOnClickStartGame([this] { OnClickStartAction(); });
	_titleMenuWidget->SetOnClickQuitGame(onQuitGame);
	_titleMenuWidget->AddToViewport();
}

void AMainGameHUD::OnClickStartAction()
{
	_stageSelectWidget = CreateWidget<UStageSelectButtonWidget>(GetWorld(), _stageSelectWidgetSubclass);
	_stageSelectWidget->AddToViewport();
	_onClickStart();
}