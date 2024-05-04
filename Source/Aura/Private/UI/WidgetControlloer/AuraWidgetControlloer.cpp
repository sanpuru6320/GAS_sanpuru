// Copyright Druid Mechanic


#include "UI/WidgetControlloer/AuraWidgetControlloer.h"

void UAuraWidgetControlloer::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}