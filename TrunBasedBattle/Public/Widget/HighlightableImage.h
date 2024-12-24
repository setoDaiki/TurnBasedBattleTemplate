// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Image.h"
#include "ForUser/Highlighter.h"
#include "HighlightableImage.generated.h"

/**
 * 
 */
UCLASS()
class TRUNBASEDBATTLE_API UHighlightableImage : public UImage, public IHighlighter
{
	GENERATED_BODY()
public:
	UHighlightableImage();
	void Init(class UTexture2D* textureWhenHighlighting);
	void Highlight()override;
	void RemoveHighlight()override;

private:
	
};
