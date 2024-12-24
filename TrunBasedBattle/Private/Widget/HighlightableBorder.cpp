// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/HighlightableBorder.h"

UHighlightableBorder::UHighlightableBorder() {
	mDefaultColor = GetBrushColor();
}

void UHighlightableBorder::Init(FLinearColor defaultColor,FLinearColor colorWhenHighlighting) {
	mDefaultColor = defaultColor;
	mColorWhenHilighting = colorWhenHighlighting;
	SetBrushColor(defaultColor);
}

void UHighlightableBorder::Highlight() {
	SetBrushColor(mColorWhenHilighting);
}

void UHighlightableBorder::RemoveHighlight() {
	SetBrushColor(mDefaultColor);
}