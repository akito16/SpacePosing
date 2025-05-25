// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Core/Utility/LevelLoader.h"
#include "MainGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SPACEPOSING_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UMainGameInstance();

private:
	UPROPERTY()
	ULevelLoader* _levelLoader;

public:
	void Test();
	ULevelLoader* GetLevelLoader() { return _levelLoader; };
};
