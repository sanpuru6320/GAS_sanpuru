// Copyright Druid Mechanic


#include "Character/EnemyCharacter.h"

#include "Aura/Aura.h"


AEnemyCharacter::AEnemyCharacter()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void AEnemyCharacter::HighlightActor()
{
    GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);//アウトラインの濃さ
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);//アウトラインの濃さ
}

void AEnemyCharacter::UnHighlightActor()
{
    GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}