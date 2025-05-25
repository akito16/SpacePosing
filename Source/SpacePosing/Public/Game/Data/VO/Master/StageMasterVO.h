#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "StageMasterVO.generated.h"

/**
 * stage_master�̃J����
 */
USTRUCT(BlueprintType)
struct SPACEPOSING_API FStageMasterData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnyWhere, BlueprintReadOnly)
	int32 id;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly)
	FString code;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly)
	int32 level;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly)
	FString name;
};

/**
 * �X�e�[�W���MasterData�N���X
 */
UCLASS()
class SPACEPOSING_API UStageMasterVO : public UObject
{
	GENERATED_BODY()

private:
	FStageMasterData _data;

public:
	void Initialize(const FStageMasterData data)
	{
		_data = data;
	}

	int32 GetId() const { return _data.id; }
	FString GetCode() const { return _data.code; }
	int32 GetHp() const { return _data.level; }
	FString GetName() const { return _data.name; }
};