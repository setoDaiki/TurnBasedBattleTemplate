// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill.h"
#include "ForUser/SkillAction.h"
#include "Combatant.h"
#include "SkillSequencer.h"
#include "ForCombatant/SkillTargets.h"
#include "Kismet/KismetSystemLibrary.h"

void USkill::Initialize(USkillAction* skillAction,class UStatuses* userStatuses,const FText& skillName,USkillTargets* targets,USkillSequencer* skillSequence) {
	mSkillAction = skillAction;
	mHasInitialized = true;
	mSkillName = skillName;
	mSkillTargets = targets;
	mSkillSequence = skillSequence;
	mUserStatuses = userStatuses;
}

void USkill::BeginUsingSkill() {
	if (!mSkillSequence) return;
	mSkillSequence->Begin();
}

void USkill::UseSkill() {
	if (!mHasInitialized) return;
	if (!mSkillTargets) return;
	mSkillAction->UseSkill(mSkillTargets,mUserStatuses);
}

FText USkill::GetName()const {
	return mSkillName;
}
