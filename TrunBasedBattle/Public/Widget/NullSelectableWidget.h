// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/SelectableWidget.h"
#include "NullSelectableWidget.generated.h"

/**
 * 
 */
UCLASS()
class TRUNBASEDBATTLE_API UNullSelectableWidget : public USelectableWidget
{
	GENERATED_BODY()
public:
	void ProcessSelectedUI(uint32 processNum)override;
};
