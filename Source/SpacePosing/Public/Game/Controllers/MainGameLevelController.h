// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainGameLevelController.generated.h"

UCLASS()
class SPACEPOSING_API AMainGameLevelController : public AActor
{
	GENERATED_BODY()
	
public:	
	AMainGameLevelController();

private:
	void Initialize();
};
