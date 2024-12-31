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
	UStaticMeshComponent* StaticMeshComponent{};

public:	
	ALSDEntity();
	virtual void Tick(float DeltaTime) override;
	// virtual void Interaction_Implementation(FHitResult hit) override;
	virtual void Interaction_Implementation(FHitResult hit) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Entity")
	UStaticMesh* Mesh{};

	virtual void OnConstruction(const FTransform& Transform) override;
};
