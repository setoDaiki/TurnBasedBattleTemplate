// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CommandAction.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TRUNBASEDBATTLE_API UCommandAction : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Execute();
	virtual void Execute_Implementation();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Undo();
	virtual void Undo_Implementation();
};
