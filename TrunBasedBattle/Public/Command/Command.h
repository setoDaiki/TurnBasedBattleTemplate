// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "Command.generated.h"

/**
 * 
 */
UCLASS()
class TRUNBASEDBATTLE_API UCommand : public UTextBlock
{
	GENERATED_BODY()
public:
	UCommand();
	
	UFUNCTION(BlueprintCallable)
	void Init(class UCommandAction* action,int index);
	void Init(class UCommandAction* action);
	UFUNCTION(BlueprintCallable)
	void AddCommandAction(class UCommandAction* action);
	UFUNCTION(BlueprintCallable)
	void SetImageHighlighter(class UHighlightableImage* imageHighlighter);
	UFUNCTION(BlueprintCallable)
	void SetBorderHighlighter(class UHighlightableBorder* highlighter);
	void SetHighligheter(class IHighlighter* highlighter);
	void Execute();
	void Undo();
	UFUNCTION(BlueprintCallable)
	void Highlight();
	UFUNCTION(BlueprintCallable)
	void RemoveHighlight();
	uint32 GetIndex()const;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSelectedDelegate);
	UPROPERTY(BlueprintAssignable)
	FSelectedDelegate OnSelected;

private:
	TArray<class UCommandAction*> mCommandActions;
	class IHighlighter* mHighlighterWidget;
	UPROPERTY(EditAnyWhere)
	int32 mIndex = 0;
};
