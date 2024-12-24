// Fill out your copyright notice in the Description page of Project Settings.


#include "ForCombatant/SkillTarget.h"

void USkillTarget::Init(class UHitPoint* hitPoint,class UStatuses* statuses,AActor* surface) {
	if(statuses) mStatuses = statuses;
	if(hitPoint) mHitPoint = hitPoint;
	if (surface) mSurface = surface;
}

class UHitPoint* USkillTarget::GetHitPoint() {
	return mHitPoint;
}

class UStatuses* USkillTarget::GetStatuses() {
	return mStatuses;
}

AActor* USkillTarget::GetSurface() {
	return mSurface;
}