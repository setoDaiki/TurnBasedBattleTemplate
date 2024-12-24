// Fill out your copyright notice in the Description page of Project Settings.


#include "ForUser/CombatantMovement.h"
#include "ForCombatant/CombatantSurface.h"
#include "ForCombatant/SkillTargets.h"
#include "ForCombatant/SkillTarget.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"

void UCombatantMovement::Update(ACombatantSurface* combatant,TArray<AActor*> targets) {
	if (!combatant) return;
	if (IsFinished()) return;
	if (mIsFirstMovement) {
		mFirstLocation = combatant->GetActorLocation();
		mIsFirstMovement = false;
	}

	if (mIsReturning) {
		Return(combatant,targets);
	}
	else {
		Go(combatant,targets);
	}
	
}

void UCombatantMovement::ToReturnMovement() {
	mIsFinishedMovement = false;
	mIsReturning = true;
}

void UCombatantMovement::ToGoMovement() {
	mIsFinishedMovement = false;
	mIsReturning = false;
}

FVector UCombatantMovement::GetCombatantFirstLocation() {
	return mFirstLocation;
}

bool UCombatantMovement::IsFinished() {
	return mIsFinishedMovement;
}

void UCombatantMovement::EndGoing() {
	mIsFinishedMovement = true;
	OnFinishedGoing.Broadcast();
}

void UCombatantMovement::EndReturning() {
	mIsFinishedMovement = true;
	OnFinishedReturning.Broadcast();
}

void UCombatantMovement::Go(ACombatantSurface* combatant, TArray<AActor*> targets) {
	EndGoing();
}
void UCombatantMovement::Return(ACombatantSurface* combatant,TArray<AActor*> targets) {
	EndReturning();
}