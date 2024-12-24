// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TurnBasePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TRUNBASEDBATTLE_API ATurnBasePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ATurnBasePlayerController();
	void SetupInputComponent()override;
	UFUNCTION(BlueprintCallable)
	void ChangeOperatingWidget(class USelectableWidget* widget);
	void HideOperatingWidget();
	void DisableOperating();

private:
	void Select(const struct FInputActionValue& inputValue);
	void DetermainWidget();
	void Cancel();
	class UInputAction* mSelectAction;
	class UInputAction* mDetermainAction;
	class UInputAction* mCancelAction;
	class UInputMappingContext* mIMC;

	class USelectableWidget* mOperatingWidget;
};
