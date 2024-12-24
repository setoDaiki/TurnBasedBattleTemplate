// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CombatantAction.generated.h"

/**
 * 
 */
UCLASS()
class TRUNBASEDBATTLE_API UCombatantAction : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Execute();
	virtual void Execute_Implementation();
};
