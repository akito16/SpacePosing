// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Utility/LevelLoader.h"
#include "Kismet/GameplayStatics.h"

/// <summary>
/// �T�u���x���̓ǂݍ���
/// </summary>
/// <param name="levelName">�ǂݍ��݃��x����</param>
/// <param name="callback">�ǂݍ��݌㏈��</param>
void ULevelLoader::OnLoadSubLevel(FName levelName, TFunction<void()> callback)
{
	_currentLevelName = levelName;
	_onLoadedAction = callback;
	auto latentInfo = this->GetLatentActionInfo();

	UGameplayStatics::LoadStreamLevel(this, levelName, true, false, latentInfo);
}

/// <summary>
/// ���x���ǂݍ��݌㏈��
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