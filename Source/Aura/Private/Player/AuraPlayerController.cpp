// Copyright Druid Mechanic


#include "Player/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"


AAuraPlayerController::AAuraPlayerController()
{
    bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
    Super::BeginPlay();
    check(AuraContext);//nullチェック

    //AddMappingContextにアクセス
    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    check(Subsystem);//nullチェック
    Subsystem->AddMappingContext(AuraContext, 0);

    bShowMouseCursor = true;
    DefaultMouseCursor = EMouseCursor::Default;

    FInputModeGameAndUI InputModeData;
    InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    InputModeData.SetHideCursorDuringCapture(false);
    SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
// void AAuraPlayerController::SetupInputComponent()
// {
//     Super::SetupInputComponent();

//     UEnhancedInputComponent* EnhanecdInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

//     EnhanecdInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
    
// }
// void AAuraPlayerController::Move(const FInputActionValue &InputActionValue)//プレイヤーの移動
// {
//     const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
//     const FRotator Rotation = GetControlRotation();
//     const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

// 	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);//前後を取得
// 	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);//左右を取得

//     if (APawn* ControlledPawn = GetPawn<APawn>())//nullチェック
// 	{
// 		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
// 		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
// 	}
// }
