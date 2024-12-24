// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SkillSequencer.generated.h"

/**
 * 
 */
UCLASS()
class TRUNBASEDBATTLE_API USkillSequencer : public UObject
{
	GENERATED_BODY()
public:
	void Initialize(class USkill* usingSkill, class ACombatantSurface* skillUser, class UAnimSequence* skillAnimation,class UCombatantMovement* movementBeforeUsingSkill,float damageTiming);
	void Begin();

private:
	class USkill* mUsingSkill;
	class ACombatantSurface* mSkillUser;
	class UCombatantMovement* mMoveBeforeUsingSkill;
	class UAnimSequence* mSkillAnimation;
	float mDamageTiming = 0.0f;
	FTimerHandle mDamageTimingTimer;
	FTimerHandle mReturningTimingTimer;
	bool mHasFinishedUsingSkill = false;
	bool mHasFinishedReturning = false;
	UFUNCTION()
	void UseSkill();
	UFUNCTION()
	void EndReturning();
	UFUNCTION()
	void BroadcastAnimation();
	UFUNCTION()
	void BroadcastEndUsingSkill();
};
