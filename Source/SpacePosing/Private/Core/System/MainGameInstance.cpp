// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/System/MainGameInstance.h"

UMainGameInstance::UMainGameInstance()
{
	UE_LOG(LogTemp, Error, TEXT("UMainGameInstance"));
	_levelLoader = NewObject<ULevelLoader>();
}

void UMainGameInstance::Test()
{
	UE_LOG(LogTemp, Error, TEXT("Test"));
}