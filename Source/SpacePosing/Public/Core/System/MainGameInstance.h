// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Core/Utility/DataTableLoader.h"
#include "Game/Data/VO/Master/UnitMasterVO.h"
#include "Game/Data/VO/Master/StageMasterVO.h"
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

	TArray<UUnitMasterVO*> GetUnitMasters() { return _unitMasters; }

	TArray<UStageMasterVO*> GetStageMasters() { return _stageMasters; }

private:
	UDataTableLoader* _dataTableLoader;

	TArray<UUnitMasterVO*> _unitMasters;

	TArray<UStageMasterVO*> _stageMasters;

	void Initialize();

	void CreateUnitMasterVOs();

	void CreateStageMasterVOs();

	// MEMO: Masterì«Ç›çûÇﬂÇÈÇÊÇ§Ç…Ç»Ç¡ÇΩÇÁçÌèú
	static TMap<int32, FName> StageList;
};
