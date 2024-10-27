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

AActor* APlayerChar::RaycastForward(float range)
{
	FHitResult hit{};
	FVector start = cameraComponent->GetComponentLocation();
	FVector end = start + (cameraComponent->GetForwardVector() * range);

	FCollisionQueryParams params(FName(TEXT("RaycastTrace")), true, this);
	params.bReturnPhysicalMaterial = false;
	params.AddIgnoredActor(this);

	bool collision = ActorLineTraceSingle(hit, start, end, ECollisionChannel::ECC_WorldStatic, params);

	if (collision)
	{
		return hit.GetActor();
	}
	else
	{
		return nullptr;
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
	AActor* hitActor = RaycastForward(400);

	if (hitActor)
	{
		ALSDEntity* entity = Cast<ALSDEntity>(hitActor);

		if (entity)
		{
			entity->Interaction();
		}
	}
}

