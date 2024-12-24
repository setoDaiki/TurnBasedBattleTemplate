// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BuffNotifier.generated.h"

/**
 * 
 */
UCLASS()
class TRUNBASEDBATTLE_API UBuffNotifier : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void Notify(int32 bufValue);
	virtual void Notify_Implementation(int32 bufValue);
};
