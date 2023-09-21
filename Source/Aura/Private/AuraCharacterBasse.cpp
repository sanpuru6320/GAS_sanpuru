// Copyright Druid Mechanic


#include "AuraCharacterBasse.h"

// Sets default values
AAuraCharacterBasse::AAuraCharacterBasse()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAuraCharacterBasse::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAuraCharacterBasse::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAuraCharacterBasse::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

