// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerChar.h"
#include "LSDEntity.h"

// Sets default values
APlayerChar::APlayerChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cameraComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APlayerChar::BeginPlay()
{
	Super::BeginPlay();
	
}

FHitResult APlayerChar::RaycastForward(float range)
{
	FHitResult hit{};
	FVector start = cameraComponent->GetComponentLocation();
	FVector end = start + (cameraComponent->GetForwardVector() * range);

	FCollisionQueryParams params(FName(TEXT("RaycastTrace")), true, this);
	params.bReturnPhysicalMaterial = false;
	params.AddIgnoredActor(this);

	bool collision = GetWorld()->LineTraceSingleByChannel(hit, start, end, ECollisionChannel::ECC_Visibility, params);
	// DrawDebugLine(GetWorld(), start, end, FColor::Green, false, 1.0f, 0, 2.0f);

	if (collision)
	{
		UE_LOG(LogTemp, Display, TEXT("Hit registered"));
		// DrawDebugPoint(GetWorld(), hit.Location, 10.0f, FColor::Red, false, 1.0f);
		return hit;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No hit registered"));
		return FHitResult();
	}
}

// Called every frame
void APlayerChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerChar::Move(float xValue, float yValue)
{
	AddMovementInput(GetActorForwardVector(), yValue);
	AddMovementInput(GetActorRightVector(), xValue);
}

void APlayerChar::MouseLook(float xValue, float yValue)
{
	AddControllerYawInput(xValue);
	AddControllerPitchInput(-yValue);
}

void APlayerChar::Interact()
{
	FHitResult hitResult = RaycastForward(400);
	ALSDEntity* entity = Cast<ALSDEntity>(hitResult.GetActor());

	if (entity)
	{
		// entity->Interaction_Implementation(hitResult);
		if (entity->Implements<UIInteractable>())
		{
			IIInteractable::Execute_Interaction(entity, hitResult);
			UE_LOG(LogTemp, Display, TEXT("Interaction confirmed"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Casting failed"));
	}
}
