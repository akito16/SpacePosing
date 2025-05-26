// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class SPACEPOSING_API FAssetPaths
{
private:
	static const inline FString ThirdPersonBlueprintPath = TEXT("/Game/ThirdPerson/Blueprints/");

	static const inline FString HUDBPPath = TEXT("/Game/Assets/Blueprints/Views/HUD/");

	static const inline FString AnimationPath = TEXT("/Game/Assets/Animations/");

public:
	static const FString GetThirdPersonBlueprintPath(FString assetName) { return ThirdPersonBlueprintPath + assetName; }

	static const FString GetHUDBPPath(FString assetName) { return HUDBPPath + assetName; }

	static const FString GetAnimationPath(FString assetName) { return AnimationPath + assetName; }
};
