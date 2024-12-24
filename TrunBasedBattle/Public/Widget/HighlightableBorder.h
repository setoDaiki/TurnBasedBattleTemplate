// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Border.h"
#include "ForUser/Highlighter.h"
#include "HighlightableBorder.generated.h"

/**
 * 
 */
UCLASS()
class TRUNBASEDBATTLE_API UHighlightableBorder : public UBorder, public IHighlighter
{
	GENERATED_BODY()
public:
	UHighlightableBorder();
	UFUNCTION(BlueprintCallable)
	void Init(FLinearColor defaultColor,FLinearColor colorWhenHighlighting);

	void Highlight()override;
	void RemoveHighlight()override;

private:
	UPROPERTY(EditAnywhere)
	FLinearColor mColorWhenHilighting;
	UPROPERTY(EditAnywhere)
	FLinearColor mDefaultColor;
};
