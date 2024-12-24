// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SkillTarget.generated.h"

/**
 * 
 */
UCLASS()
class TRUNBASEDBATTLE_API USkillTarget : public UObject
{
	GENERATED_BODY()
public:
	void Init(class UHitPoint* targetHitPoint,class UStatuses* targetStatus,AActor* targetSurface);
	UHitPoint* GetHitPoint();
	UStatuses* GetStatuses();
	AActor* GetSurface();

private:
	class UStatuses* mStatuses;
	class UHitPoint* mHitPoint;
	AActor* mSurface;
};
