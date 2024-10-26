// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IInteractable.h"
#include "LSDEntity.generated.h"

UCLASS()
class LSD24_API ALSDEntity : public AActor, public IIInteractable
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void Interaction();

public:	
	ALSDEntity();
	virtual void Tick(float DeltaTime) override;

};
