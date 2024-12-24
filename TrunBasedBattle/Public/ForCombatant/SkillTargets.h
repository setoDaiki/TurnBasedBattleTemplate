// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SkillTargets.generated.h"

/**
 * 
 */
UCLASS()
class TRUNBASEDBATTLE_API USkillTargets : public UObject
{
	GENERATED_BODY()
public:
	USkillTargets();
	void Add(class USkillTarget* target);
	void RemoveAll();
	TArray<class USkillTarget*> Get();

private:
	TArray<class USkillTarget*> mTargets;
	UFUNCTION()
	void Remove(AActor* removeActor);
	FScriptDelegate mDelegate;
};
