// Copyright Druid Mechanic

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBasse.h"
#include "Interaction/EnemyInterface.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AEnemyCharacter : public AAuraCharacterBasse, public IEnemyInterface
{
	GENERATED_BODY()

public:
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	
	AEnemyCharacter();
};
