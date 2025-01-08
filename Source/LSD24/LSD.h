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

USTRUCT(BlueprintType)
struct FLSDItem
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item")
	FString itemName{};
};

USTRUCT(BlueprintType)
struct FLSDQuest
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Quest")
	FString questName{};

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Quest")
	FString objective{};

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Quest")
	bool complete{};

	bool operator==(const FLSDQuest& Other) const
	{
		// Compare on quest name.
		return questName == Other.questName;
	}
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

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Global Game Values")
	TArray<FLSDItem> playerItems{};

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Global Game Values")
	TArray<FLSDQuest> questLog{};

	UFUNCTION(BlueprintCallable, Category = "Global Game Values")
	void AddToInventory(FLSDItem newItem);

	UFUNCTION(BlueprintCallable, Category = "Global Game Values")
	void ChangeStoryStage(EGameStage newStage);

	UFUNCTION(BlueprintCallable, Category = "Global Game Values")
	void AddNewQuest(FLSDQuest newQuest);

	UFUNCTION(BlueprintCallable, Category = "Global Game Values")
	void CompleteQuest(FLSDQuest newQuest);
};