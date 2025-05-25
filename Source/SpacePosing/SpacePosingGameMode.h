#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SpacePosingGameMode.generated.h"

UCLASS(minimalapi)
class ASpacePosingGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASpacePosingGameMode();

private:
	static const inline FName OnLoadedActionName = "OnLoadedLevelAction";

	APlayerController* _playerController;

	FName _currentLevelName;

	TFunction<void()> _onLoadedAction;

	virtual void BeginPlay() override;

	void OnStartGame();

	void OnQuitGame();

	UFUNCTION()
	void OnLoadedLevelAction();

	FLatentActionInfo GetLatentActionInfo()
	{
		FLatentActionInfo latentInfo;
		latentInfo.CallbackTarget = this;
		latentInfo.ExecutionFunction = OnLoadedActionName;
		latentInfo.Linkage = 0;
		latentInfo.UUID = 1;

		return latentInfo;
	}

public:
	void SetControlOnlyUI();

	void SetControlOnlyGame();

	void OnLoadSubLevel(FName levelName, TFunction<void()> callback);
};



