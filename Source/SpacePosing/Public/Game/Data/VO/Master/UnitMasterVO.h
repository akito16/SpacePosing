#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "UnitMasterVO.generated.h"

/**
 * unit_master data
 */
USTRUCT(BlueprintType)
struct SPACEPOSING_API FUnitMasterData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnyWhere, BlueprintReadOnly)
	int32 id;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly)
	FString code;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly)
	FString name;
};

UCLASS()
class SPACEPOSING_API UUnitMasterVO : public UObject
{
	GENERATED_BODY()

private:
	FUnitMasterData _data;

public:
	void Initialize(const FUnitMasterData data)
	{
		_data = data;
	}

	int32 GetId() const { return _data.id; }
	FString GetCode() const { return _data.code; }
	FString GetName() const { return _data.name; }
};
