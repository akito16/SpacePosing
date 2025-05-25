#include "Game/Views/Widget/TitleMenuWidget.h"
#include "Game/Data/VO/Master/UnitMasterVO.h"
#include "Core/System/MainGameInstance.h"

UTitleMenuWidget::UTitleMenuWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
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
	//this->SetVisibility(ESlateVisibility::Hidden);
}

void UTitleMenuWidget::OnClickQuitButton()
{
	_onQuitGame();
}