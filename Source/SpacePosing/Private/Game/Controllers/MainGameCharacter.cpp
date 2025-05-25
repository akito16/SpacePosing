// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/Controllers/MainGameCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMainGameCharacter::AMainGameCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCharacterMovement()->SetMovementMode(MOVE_Flying);
}

// Called when the game starts or when spawned
void AMainGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

