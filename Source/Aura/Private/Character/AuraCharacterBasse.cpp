// Copyright Druid Mechanic


#include "Character/AuraCharacterBasse.h"

// Sets default values
AAuraCharacterBasse::AAuraCharacterBasse()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));//SKMのソケットを使用
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

UAbilitySystemComponent* AAuraCharacterBasse::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
// Called when the game starts or when spawned
void AAuraCharacterBasse::BeginPlay()
{
	Super::BeginPlay();
	
}

