// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/HighlightableImage.h"
#include "Components/Image.h"

UHighlightableImage::UHighlightableImage() {
	SetOpacity(0.0f);
}

void UHighlightableImage::Init(UTexture2D* textureWhenHighlighting) {
	if (textureWhenHighlighting) SetBrushFromTexture(textureWhenHighlighting);
	SetOpacity(0.0f);
}

void UHighlightableImage::Highlight() {
	SetOpacity(1.0f);
}

void UHighlightableImage::RemoveHighlight() {
	SetOpacity(0.0f);
}