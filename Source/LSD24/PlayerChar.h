// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "PlayerChar.generated.h"

UCLASS()
class LSD24_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Player")
	UCameraComponent* cameraComponent{};

public:
	APlayerChar();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Utility", meta = (ReturnDisplayName = "Hit Actor"))
	FHitResult RaycastForward(float range);
	
	UFUNCTION(BlueprintCallable, Category = "Gameplay/Movement")
	void Move(float xValue, float yValue);

	UFUNCTION(BlueprintCallable, Category = "Gameplay/Movement")
	void MouseLook(float xValue, float yValue);

	UFUNCTION(BlueprintCallable, Category = "Gameplay/Actions")
	void Interact();

	// Blueprint Functions.

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Visual Effects")
	void FadeIn();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Visual Effects")
	void FadeOut();
};
