// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Game/Views/Widget/StageSelectButtonWidget.h"

void UStageSelectButtonWidget::Setup(int32 stageNum, FName stageName, TFunction<void()> onClick)
{
	_stageNum = stageNum;
	_stageName = stageName;
	_onClick = onClick;
}

void UStageSelectButtonWidget::OnClickButton()
{
	_onClick();
}