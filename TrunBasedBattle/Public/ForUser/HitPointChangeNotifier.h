// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HitPointChangeNotifier.generated.h"

/**
 * 
 */
UCLASS()
class TRUNBASEDBATTLE_API UHitPointChangeNotifier : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void NotifyRecovery(int32 recoverVal);
	virtual void NotifyRecovery_Implementation(int32 recoverVal);

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void NotifyDamage(int32 damageVal);
	virtual void NotifyDamage_Implementation(int32 damageVal);
};
