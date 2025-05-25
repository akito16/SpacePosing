#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Game/Views/TitleMenuWidget.h"
#include "TitleHUD.generated.h"

/**
 * タイトル用HUD
 */
UCLASS()
class SPACEPOSING_API ATitleHUD : public AHUD
{
	GENERATED_BODY()
	
private:
	TSubclassOf<UTitleMenuWidget> _titleMenuWidgetSubclass;
	UTitleMenuWidget* _titleMenuWidget;

public:
	ATitleHUD();
	
	void Setup(TFunction<void()> onStartGame, TFunction<void()> onQuitGame);
};
