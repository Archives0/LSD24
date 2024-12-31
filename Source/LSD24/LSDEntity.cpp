// Fill out your copyright notice in the Description page of Project Settings.


#include "LSDEntity.h"

// Sets default values
ALSDEntity::ALSDEntity()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(StaticMeshComponent);
	// StaticMeshComponent->SetupAttachment(RootComponent);
}

void ALSDEntity::OnConstruction(const FTransform& Transform)
{
	StaticMeshComponent->SetStaticMesh(Mesh);
}

// Called when the game starts or when spawned
void ALSDEntity::BeginPlay()
{
	Super::BeginPlay();
	
}

//void ALSDEntity::Interaction()
//{
//	UE_LOG(LogTemp, Display, TEXT("No derived interaction found, defaulted to base."));
//}

// Called every frame
void ALSDEntity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALSDEntity::Interaction_Implementation(FHitResult hit)
{
	// Interactions defined in blueprints inheriting from this class.

	UE_LOG(LogTemp, Display, TEXT("No derived interaction found, defaulted to base."));
}