// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillManager.generated.h"


UCLASS(Blueprintable)
class TRUNBASEDBATTLE_API USkillManager : public UObject
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USkillManager();
	void Init(class UCombatantAnimEvent* animEvent);
	class USkillSelectorWidget* CreateSkillWidget(UWorld* world,class UEnemySelectorWidget* enemySelectorWidget,class UActionDeque* actionDeque);
	void Add(class USkill* skill);

private:
	UPROPERTY(EditAnywhere)
	TArray<class USkill*> mSkills;
	void CreateSkillCommand(class USkill* skill);
	void BroadCastSkillUsing(class UAnimSequence* anim);
	UFUNCTION()
	void BroadCastEndUsingSkill();
	TObjectPtr<class UCombatantAnimEvent> mAnimEvent;
};
