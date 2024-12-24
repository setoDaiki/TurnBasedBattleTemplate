// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SkillAction.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TRUNBASEDBATTLE_API USkillAction : public UObject
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void UseSkill(class USkillTargets* targts,class UStatuses* userStatuses);
	virtual void UseSkill_Implementation(class USkillTargets* targets,class UStatuses* userStatuses);
};