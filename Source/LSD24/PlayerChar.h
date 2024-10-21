// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerChar.generated.h"

UCLASS()
class LSD24_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	APlayerChar();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable, Category = "Player")
	void Move(float xValue, float yValue);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void MouseLook(float xValue, float yValue);
};
