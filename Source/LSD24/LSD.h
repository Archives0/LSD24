// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LSD.generated.h"

USTRUCT(BlueprintType)
struct FDialogue
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue System")
	TArray<FString> textOptions{};
};

UENUM(BlueprintType)
enum class EGameStage : uint8
{
	STAGEONE,
	STAGETWO,
	STAGETHREE,
	STAGEFOUR
};

/**
 * 
 */
UCLASS()
class LSD24_API ULSD : public UGameInstance
{
	GENERATED_BODY()


public:

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Global Game Values")
	EGameStage storyStage{};
};
