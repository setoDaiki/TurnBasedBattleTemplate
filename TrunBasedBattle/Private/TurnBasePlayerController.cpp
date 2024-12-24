// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnBasePlayerController.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Widget/SelectableWidget.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Combatant.h"

ATurnBasePlayerController::ATurnBasePlayerController() {
	mSelectAction = LoadObject<UInputAction>(nullptr,TEXT("/Game/Input/IA_Select"));
	mDetermainAction = LoadObject<UInputAction>(nullptr,TEXT("/Game/Input/IA_DetermainAction"));
	mCancelAction = LoadObject<UInputAction>(nullptr, TEXT("/Game/Input/IA_Cancel"));
	mIMC = LoadObject<UInputMappingContext>(nullptr,TEXT("/Game/Input/IMC_PlayerTemp"));
}

void ATurnBasePlayerController::SetupInputComponent() {
	Super::SetupInputComponent();
	EnableInput(this);
	if (UEnhancedInputComponent* enhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent)) {
		enhancedInputComponent->BindAction(mSelectAction,ETriggerEvent::Triggered,this,&ATurnBasePlayerController::Select);
		enhancedInputComponent->BindAction(mDetermainAction,ETriggerEvent::Triggered,this,&ATurnBasePlayerController::DetermainWidget);
		enhancedInputComponent->BindAction(mCancelAction, ETriggerEvent::Triggered, this, &ATurnBasePlayerController::Cancel);
	}
	if (APlayerController* PlayerController = Cast<APlayerController>(this))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(mIMC, 0);
		}
	}
}

void ATurnBasePlayerController::ChangeOperatingWidget(USelectableWidget* widget) {
	if (!widget) return;
	mOperatingWidget = widget;
}

void ATurnBasePlayerController::Select(const FInputActionValue& actionValue) {
	if (!mOperatingWidget) return;
	FVector2D actionVec = actionValue.Get<FVector2D>();
	actionVec *= -1;
	mOperatingWidget->ProcessSelectedUI(actionVec.Y);
}

void ATurnBasePlayerController::Cancel() {
	if (!mOperatingWidget) return;
	mOperatingWidget->Canceled();
}

void ATurnBasePlayerController::DetermainWidget() {
	if ((!mOperatingWidget))return;
	mOperatingWidget->Determained();	
}

