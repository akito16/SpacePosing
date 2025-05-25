// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelLoader.generated.h"

/**
 * 
 */
UCLASS()
class SPACEPOSING_API ULevelLoader : public UObject
{
	GENERATED_BODY()

private:
	static const inline FName OnLoadedActionName = "OnLoadedLevelAction";

	FName _currentLevelName;
	TFunction<void()> _onLoadedAction;

	FLatentActionInfo GetLatentActionInfo();

	UFUNCTION()
	void OnLoadedLevelAction();

public:
	void OnLoadSubLevel(FName levelName, TFunction<void()> callback);
};
