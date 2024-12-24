// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CombatantAnimEvent.generated.h"

/**
 * 
 */
UCLASS()
class TRUNBASEDBATTLE_API UCombatantAnimEvent : public UObject
{
	GENERATED_BODY()
public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAnimEvent, UAnimSequence*, animSequence);

	UPROPERTY(BlueprintAssignable)
	FAnimEvent OnNeedToBeginAnim;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEndAnimEvent);
	UPROPERTY(BlueprintAssignable)
	FEndAnimEvent OnEndAnim;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSkillEvent);
	UPROPERTY(BlueprintAssignable)
	FSkillEvent OnEndUsingSkill;
};
