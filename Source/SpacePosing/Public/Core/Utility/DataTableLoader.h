#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DataTableLoader.generated.h"

/**
 * 
 */
UCLASS()
class SPACEPOSING_API UDataTableLoader : public UObject
{
	GENERATED_BODY()

private:
	TMap<FName, UDataTable*> _loadedMasterDataTables;

public:
	void LoadAllMasterDataTables(TArray<FName> masterTablePaths);

	UDataTable* GetDataTable(FName tableName) const
	{
		return _loadedMasterDataTables.Contains(tableName) ? _loadedMasterDataTables[tableName] : nullptr;
	}
};
