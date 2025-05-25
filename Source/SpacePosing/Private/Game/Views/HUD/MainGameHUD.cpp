// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/Views/HUD/MainGameHUD.h"

AMainGameHUD::AMainGameHUD()
{
	static ConstructorHelpers::FClassFinder<UTitleMenuWidget> TitleMenuWidget(TEXT("/Game/Assets/Blueprints/Views/Widget/BPW_TitleMenuWidget"));
	_titleMenuWidgetSubclass = TitleMenuWidget.Class;
}

void AMainGameHUD::SetupTitle(TFunction<void()> onStartGame, TFunction<void()> onQuitGame)
{
	_titleMenuWidget = CreateWidget<UTitleMenuWidget>(GetWorld(), _titleMenuWidgetSubclass);
	_titleMenuWidget->SetOnClickStartGame(onStartGame);
	_titleMenuWidget->SetOnClickQuitGame(onQuitGame);
	_titleMenuWidget->AddToViewport();
}
