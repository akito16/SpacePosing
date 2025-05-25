#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleMenuWidget.generated.h"

/**
 * タイトルメニューUI
 */
UCLASS()
class SPACEPOSING_API UTitleMenuWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	TFunction<void()> _onStartGame;

	TFunction<void()> _onQuitGame;

public:
	UTitleMenuWidget(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable)
	void OnClickStartButton();

	UFUNCTION(BlueprintCallable)
	void OnClickQuitButton();

	void SetOnClickStartGame(TFunction<void()> onStart);

	void SetOnClickQuitGame(TFunction<void()> onQuit);

	void SwitchActiveView(bool bIsActive);
};
