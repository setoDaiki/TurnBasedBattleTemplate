// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SelectableWidget.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TRUNBASEDBATTLE_API USelectableWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void Add(class UCommand* command);
	void Remove(class UCommand* command);
	UFUNCTION(BlueprintCallable)
	void SortCommands();
	void ClearCommands();
	virtual void ProcessSelectedUI(uint32 processNum);
	void Determained();
	void Canceled();
	virtual void NativeConstruct()override;

	UFUNCTION(BlueprintCallable)
	void ToSelectableState();

	UFUNCTION(BlueprintCallable)
	void SetPrevWidget(class USelectableWidget* creater);

	void UndoCommands();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSelectedDelegate);
	UPROPERTY(BlueprintAssignable)
	FSelectedDelegate OnSelected;

protected:
	class UCommand* GetSelectedUI();

private:
	TArray<class UCommand*> mSelectableUIs;
	int32 mFocusCommandIndex;
	USelectableWidget* mMadeMeWidget;
};
