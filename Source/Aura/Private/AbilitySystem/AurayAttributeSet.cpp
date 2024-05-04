// Copyright Druid Mechanic


#include "AbilitySystem/AurayAttributeSet.h"

#include "Net/UnrealNetwork.h"

UAurayAttributeSet::UAurayAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);
	InitMana(50.f);
	InitMaxMana(50.f);
}

void UAurayAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAurayAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAurayAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
}

void UAurayAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurayAttributeSet, Health, OldHealth);
}

void UAurayAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurayAttributeSet, MaxHealth, OldMaxHealth);
}

void UAurayAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurayAttributeSet, Mana, OldMana);
}

void UAurayAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAurayAttributeSet, MaxMana, OldMaxMana);
}