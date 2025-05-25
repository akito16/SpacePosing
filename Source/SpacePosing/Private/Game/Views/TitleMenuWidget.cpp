#include "Game/Views/TitleMenuWidget.h"

UTitleMenuWidget::UTitleMenuWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("UTitleMenuWidget::UTitleMenuWidget"));
}

void UTitleMenuWidget::SetOnClickStartGame(TFunction<void()> onStart)
{
	_onStartGame = onStart;
}

void UTitleMenuWidget::SetOnClickQuitGame(TFunction<void()> onQuit)
{
	_onQuitGame = onQuit;
}

void UTitleMenuWidget::OnClickStartButton()
{
	_onStartGame();
	this->SetVisibility(ESlateVisibility::Hidden);
	UE_LOG(LogTemp, Warning, TEXT("OnClickStartButton"));
}

void UTitleMenuWidget::OnClickQuitButton()
{
	_onQuitGame();
	UE_LOG(LogTemp, Warning, TEXT("OnClickQuitButton"));
}