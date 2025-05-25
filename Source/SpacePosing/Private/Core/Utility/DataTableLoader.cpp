#include "Core/Utility/DataTableLoader.h"

void UDataTableLoader::LoadAllMasterDataTables(TArray<FName> masterTablePaths)
{
	for (FName masterDataTablePath : masterTablePaths)
	{
		UDataTable* dataTable = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), nullptr, *masterDataTablePath.ToString()));
		if (dataTable)
		{
			_loadedMasterDataTables.Add(masterDataTablePath, dataTable);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Not Found DataTable: %s"), *masterDataTablePath.ToString());
		}
	}
}