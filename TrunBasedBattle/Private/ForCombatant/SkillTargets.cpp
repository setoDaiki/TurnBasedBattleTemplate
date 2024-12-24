// Fill out your copyright notice in the Description page of Project Settings.


#include "ForCombatant/SkillTargets.h"
#include "ForCombatant/SkillTarget.h"
#include "Kismet/KismetSystemLibrary.h"

USkillTargets::USkillTargets() {
	mDelegate.BindUFunction(this,FName("Remove"));
}

void USkillTargets::Add(class USkillTarget* target) {
	mTargets.Add(target);
	AActor* surface = target->GetSurface();
	if (!surface) return;
	if (surface->OnDestroyed.Contains(mDelegate)) return;
	target->GetSurface()->OnDestroyed.Add(mDelegate);
}

TArray<class USkillTarget*> USkillTargets::Get() {
	return mTargets;
}

void USkillTargets::RemoveAll() {
	mTargets.Empty();
}

void USkillTargets::Remove(AActor* removeActor) {
	USkillTarget* removeTarget = nullptr;
	for (auto target : mTargets) {
		if (target->GetSurface() == removeActor) {
			removeTarget = target;
		}
	}
	mTargets.Remove(removeTarget);
}