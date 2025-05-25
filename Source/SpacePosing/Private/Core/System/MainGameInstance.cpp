// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/System/MainGameInstance.h"
#include "Game/Data/Constants/MasterDataTables.h"

UMainGameInstance::UMainGameInstance()
{
	this->Initialize();
}

void UMainGameInstance::Initialize()
{
	_dataTableLoader = NewObject<UDataTableLoader>();
	_dataTableLoader->LoadAllMasterDataTables(FMasterDataTables::GetAllMasterTablePaths());
	//CreateUnitMasterVOs();
	//CreateStageMasterVOs();
}

TMap<int32, FName> UMainGameInstance::StageList = {
	{1, "Stage1"},
	{2, "Stage2"},
	{3, "Stage3"}
};

/*
void UMainGameInstance::CreateUnitMasterVOs()
{
	UDataTable* table = _dataTableLoader->GetDataTable(FMasterDataTables::UnitMaster);
	if (table)
	{
		TArray<FName> rowNames = table->GetRowNames();
		for (auto rowName : rowNames)
		{
			const FUnitMasterData* data = table->FindRow<FUnitMasterData>(rowName, FString());
			if (data)
			{
				UUnitMasterVO* masterVO = NewObject<UUnitMasterVO>();
				masterVO->Initialize(*data);
				_unitMasters.Add(masterVO);
			}
		}
	}
}

void UMainGameInstance::CreateStageMasterVOs()
{
	UDataTable* table = _dataTableLoader->GetDataTable(FMasterDataTables::StageMaster);
	if (table)
	{
		TArray<FName> rowNames = table->GetRowNames();
		for (auto rowName : rowNames)
		{
			const FStageMasterData* data = table->FindRow<FStageMasterData>(rowName, FString());
			if (data)
			{
				UStageMasterVO* masterVO = NewObject<UStageMasterVO>();
				masterVO->Initialize(*data);
				_stageMasters.Add(masterVO);
			}
		}
	}
}
*/