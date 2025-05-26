#include "SpacePosingGameMode.h"
#include "SpacePosingCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Core/System/MainGameInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "Game/Views/HUD/MainGameHUD.h"
#include "Game/Data/Constants/AssetPaths.h"

ASpacePosingGameMode::ASpacePosingGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(*FAssetPaths::GetThirdPersonBlueprintPath("BP_ThirdPersonCharacter"));
	static ConstructorHelpers::FClassFinder<AHUD> MainHUDBPClass(*FAssetPaths::GetHUDBPPath("BP_MainGameHUD"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	if (MainHUDBPClass.Class != NULL)
	{
		HUDClass = MainHUDBPClass.Class;
	}
	this->OnLoadSubLevel("MainGame", NULL);
}

void ASpacePosingGameMode::BeginPlay()
{
	Super::BeginPlay();

	_playerController = GetWorld()->GetFirstPlayerController();
	this->SetControlOnlyUI();
	auto currentHUD = GetWorld()->GetFirstPlayerController()->GetHUD();
	AMainGameHUD* mainHUD = Cast<AMainGameHUD>(currentHUD);
	mainHUD->SetupTitle([this] { OnStartGame(); }, [this] { OnQuitGame(); });
}

/// <summary>
/// �T�u���x���̓ǂݍ���
/// </summary>
/// <param name="levelName">�ǂݍ��݃��x����</param>
/// <param name="callback">�ǂݍ��݌㏈��</param>
void ASpacePosingGameMode::OnLoadSubLevel(FName levelName, TFunction<void()> callback)
{
	_currentLevelName = levelName;
	_onLoadedAction = callback;
	auto latentInfo = this->GetLatentActionInfo();

	UGameplayStatics::LoadStreamLevel(this, levelName, true, false, latentInfo);
}

/// <summary>
/// ���x���ǂݍ��݌㏈��
/// </summary>
void ASpacePosingGameMode::OnLoadedLevelAction()
{
	UE_LOG(LogTemp, Error, TEXT("OnLoadedLevelAction"));
	if (_onLoadedAction)
	{
		_onLoadedAction();
	}
}

/// <summary>
/// �Q�[���J�n����
/// </summary>
void ASpacePosingGameMode::OnStartGame()
{
	this->SetControlOnlyGame();
	UE_LOG(LogTemp, Error, TEXT("OnStartGame"));
}

/// <summary>
/// �Q�[���I������
/// </summary>
void ASpacePosingGameMode::OnQuitGame()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
	UE_LOG(LogTemp, Error, TEXT("OnQuitGame"));
}

/// <summary>
/// UI����̂�
/// </summary>
void ASpacePosingGameMode::SetControlOnlyUI()
{
	if (!IsValid(_playerController)) return;
	_playerController->SetInputMode(FInputModeUIOnly());
	_playerController->bShowMouseCursor = true;
}

/// <summary>
/// �Q�[������̂�
/// </summary>
void ASpacePosingGameMode::SetControlOnlyGame()
{
	if (!IsValid(_playerController)) return;
	_playerController->SetInputMode(FInputModeGameOnly());
	_playerController->bShowMouseCursor = false;
	_playerController->SetIgnoreMoveInput(false);
	_playerController->SetIgnoreLookInput(false);
}