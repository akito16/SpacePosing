// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CoreGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SPACEPOSING_API ACoreGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ACoreGameMode();

private:
	FName _currentLevelName;
	TFunction<void()> _onLoadedAction;

	FLatentActionInfo GetLatentActionInfo();

	UFUNCTION()
	void OnLoadedLevelAction();

public:
	static const inline FName OnLoadedActionName = "OnLoadedLevelAction";

	void OnLoadLevel(FName levelName, TFunction<void()> callback);
};
