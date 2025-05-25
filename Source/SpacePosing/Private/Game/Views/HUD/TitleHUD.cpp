#include "Game/Views/HUD/TitleHUD.h"

ATitleHUD::ATitleHUD()
{
	static ConstructorHelpers::FClassFinder<UTitleMenuWidget> TitleMenuWidget(TEXT("/Game/Assets/Blueprints/Views/Widget/BPW_TitleMenuWidget"));
	_titleMenuWidgetSubclass = TitleMenuWidget.Class;
}

void ATitleHUD::Setup(TFunction<void()> onStartGame, TFunction<void()> onQuitGame)
{
	_titleMenuWidget = CreateWidget<UTitleMenuWidget>(GetWorld(), _titleMenuWidgetSubclass);
	_titleMenuWidget->SetOnClickStartGame(onStartGame);
	_titleMenuWidget->SetOnClickQuitGame(onQuitGame);
	_titleMenuWidget->AddToViewport();
}
