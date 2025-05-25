// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Utility/LevelLoader.h"
#include "Kismet/GameplayStatics.h"

/// <summary>
/// サブレベルの読み込み
/// </summary>
/// <param name="levelName">読み込みレベル名</param>
/// <param name="callback">読み込み後処理</param>
void ULevelLoader::OnLoadSubLevel(FName levelName, TFunction<void()> callback)
{
	_currentLevelName = levelName;
	_onLoadedAction = callback;
	auto latentInfo = this->GetLatentActionInfo();

	UGameplayStatics::LoadStreamLevel(this, levelName, true, false, latentInfo);
}

/// <summary>
/// レベル読み込み後処理
/// </summary>
void ULevelLoader::OnLoadedLevelAction()
{
	UE_LOG(LogTemp, Error, TEXT("OnLoadedLevelAction"));
	if (_onLoadedAction)
	{
		_onLoadedAction();
	}
}

FLatentActionInfo ULevelLoader::GetLatentActionInfo()
{
	FLatentActionInfo latentInfo;
	latentInfo.CallbackTarget = this;
	latentInfo.ExecutionFunction = OnLoadedActionName;
	latentInfo.Linkage = 0;
	latentInfo.UUID = 1;

	return latentInfo;
}