// Fill out your copyright notice in the Description page of Project Settings.


#include "ForCombatant/CombatantSurface.h"
#include "ForCombatant/CombatantAnimEvent.h"
#include "ForCombatant/SkillTargets.h"
#include "Animation/AnimInstance.h"
#include "ForCombatant/SkillTarget.h"
#include "ForUser/CombatantMovement.h"
#include "TimerManager.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACombatantSurface::ACombatantSurface()
{
	
}

// Called when the game starts or when spawned
void ACombatantSurface::BeginPlay()
{
	Super::BeginPlay();
	mMovement = nullptr;
}

void ACombatantSurface::Init(UCombatantAnimEvent* animEvent,class USkillTargets* targets) {
	if (targets) mTargets = targets;
	if (!animEvent) return;
	mAnimEvent = animEvent;
	mAnimEvent->OnNeedToBeginAnim.AddDynamic(this,&ACombatantSurface::BroadcastEvent);
}

void ACombatantSurface::ChangeMovement(UCombatantMovement* movementBeforeUsingSkill) {
	if (movementBeforeUsingSkill) mMovement = movementBeforeUsingSkill;
}

void ACombatantSurface::BroadcastEvent(class UAnimSequence* animSequece) {
	if (!animSequece) return;
	OnNeedToStartAnim.Broadcast(animSequece);
}


void ACombatantSurface::Tick(float deltaTime) {
	Super::Tick(deltaTime);
	if (!mMovement) return;
	if (mMovement->IsFinished()) return;
	TArray<AActor*> targetSurfaces;
	TArray<USkillTarget*> targets = mTargets->Get();
	for (auto target : targets) {
		targetSurfaces.Add(target->GetSurface());
	}
	mMovement->Update(this,targetSurfaces);
}