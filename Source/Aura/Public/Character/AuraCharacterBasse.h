// Copyright Druid Mechanic

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBasse.generated.h"

UCLASS(Abstract)
class AURA_API AAuraCharacterBasse : public ACharacter
{
	GENERATED_BODY()

public:
	AAuraCharacterBasse();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
