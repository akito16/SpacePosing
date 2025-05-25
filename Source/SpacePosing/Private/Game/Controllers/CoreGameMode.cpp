// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/Controllers/CoreGameMode.h"
#include "Kismet/GameplayStatics.h"

ACoreGameMode::ACoreGameMode()
{
	UE_LOG(LogTemp, Error, TEXT("ACoreGameMode"));
	this->OnLoadLevel("MainGame", NULL);
}

void ACoreGameMode::OnLoadLevel(FName levelName, TFunction<void()> callback)
{
	_currentLevelName = levelName;
	_onLoadedAction = callback;
	auto latentInfo = this->GetLatentActionInfo();

	UGameplayStatics::LoadStreamLevel(this, levelName, true, false, latentInfo);
}

void ACoreGameMode::OnLoadedLevelAction()
{
	UE_LOG(LogTemp, Error, TEXT("OnLoadedLevelAction"));
	if (_onLoadedAction) 
	{
		_onLoadedAction();
	}
}

FLatentActionInfo ACoreGameMode::GetLatentActionInfo()
{
	FLatentActionInfo latentInfo;
	latentInfo.CallbackTarget = this;
	latentInfo.ExecutionFunction = OnLoadedActionName;
	latentInfo.Linkage = 0;
	latentInfo.UUID = 1;

	return latentInfo;
}