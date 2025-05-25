// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StageSelectButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class SPACEPOSING_API UStageSelectButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
private:
	int32 _stageNum;
	FName _stageName;
	TFunction<void()> _onClick;

public:
	void Setup(int32 stageNum, FName stageName, TFunction<void()> onClick);

	UFUNCTION(BlueprintCallable)
	void OnClickButton();
};
