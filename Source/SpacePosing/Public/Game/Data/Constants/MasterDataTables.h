#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class SPACEPOSING_API FMasterDataTables
{
private:
	static const inline FString MasterTablePath = TEXT("/Game/Assets/MasterData/");

public:
	static const inline FName UnitMaster = FName(*(MasterTablePath + TEXT("unit_masters")));
	static const inline FName StageMaster = FName(*(MasterTablePath + TEXT("stage_masters")));

	static const TArray<FName> GetAllMasterTablePaths()
	{
		return {
			UnitMaster,
			StageMaster
		};
	}
};
