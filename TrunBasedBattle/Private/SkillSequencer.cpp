// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillSequencer.h"
#include "Skill.h"
#include "ForCombatant/CombatantSurface.h"
#include "ForCombatant/CombatantAnimEvent.h"
#include "ForUser/CombatantMovement.h"
#include "Animation/AnimSequence.h"
#include "Kismet/KismetSystemLibrary.h"

void USkillSequencer::Initialize(USkill* usingSkill, ACombatantSurface* skillUser, UAnimSequence* skillAnimation,UCombatantMovement* movementBeforeUsingSkill,float damegeTiming) {
	if (usingSkill) mUsingSkill = usingSkill;
	if (skillUser)  mSkillUser = skillUser;
	if (skillAnimation) mSkillAnimation = skillAnimation;
	if (movementBeforeUsingSkill) mMoveBeforeUsingSkill = movementBeforeUsingSkill;
	mDamageTiming = damegeTiming;
	if (!mMoveBeforeUsingSkill) return;
	mMoveBeforeUsingSkill->OnFinishedGoing.AddDynamic(this, &USkillSequencer::BroadcastAnimation);
	mMoveBeforeUsingSkill->OnFinishedReturning.AddDynamic(this, &USkillSequencer::EndReturning);
}

void USkillSequencer::Begin() {
	mMoveBeforeUsingSkill->ToGoMovement();
	mSkillUser->ChangeMovement(mMoveBeforeUsingSkill);
}

void USkillSequencer::BroadcastAnimation() {
	if (!mUsingSkill) return;
	if (!mSkillUser) return;
	if (!mSkillAnimation) return;
	mUsingSkill->OnStartUsingSkill.Broadcast(mSkillAnimation);
	mSkillUser->GetWorld()->GetTimerManager().SetTimer(mReturningTimingTimer, mMoveBeforeUsingSkill, &UCombatantMovement::ToReturnMovement, mSkillAnimation->GetPlayLength(), false);
	mSkillUser->GetWorld()->GetTimerManager().SetTimer(mDamageTimingTimer, this, &USkillSequencer::UseSkill, mDamageTiming, false);
}

void USkillSequencer::UseSkill() {
	if (!mUsingSkill) return;
	mUsingSkill->UseSkill();
	mHasFinishedUsingSkill = true;
	if (mHasFinishedReturning) {
		BroadcastEndUsingSkill();
	}
}

void USkillSequencer::EndReturning() {
	mHasFinishedReturning = true;
	if (mHasFinishedUsingSkill) {
		BroadcastEndUsingSkill();
	}
}

void USkillSequencer::BroadcastEndUsingSkill() {
	if (!mUsingSkill) return;
	mUsingSkill->OnEndUsingSkill.Broadcast();
	mHasFinishedReturning = false;
	mHasFinishedUsingSkill = false;
}