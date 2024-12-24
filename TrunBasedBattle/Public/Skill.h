// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Skill.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TRUNBASEDBATTLE_API USkill : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void Initialize(class USkillAction* skillAction,class UStatuses* userStatuses,const FText& skillName,class USkillTargets* targets,class USkillSequencer* skillSequence);
	
	void BeginUsingSkill();

	UFUNCTION(BlueprintCallable)
	void UseSkill();

	UFUNCTION(BlueprintCallable)
	FText GetName()const;

	
	DECLARE_MULTICAST_DELEGATE_OneParam(FUsingSkillEvent,class UAnimSequence*);
	FUsingSkillEvent OnStartUsingSkill;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEndUsingSkillEvent);
	FEndUsingSkillEvent OnEndUsingSkill;

private:
	class USkillAction* mSkillAction;
	class USkillSequencer* mSkillSequence;
	class USkillTargets* mSkillTargets;
	class UStatuses* mUserStatuses;
	FText mSkillName;
	bool mHasInitialized = false;
};
