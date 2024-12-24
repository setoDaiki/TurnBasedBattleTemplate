// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CombatantSurface.generated.h"

UCLASS()
class TRUNBASEDBATTLE_API ACombatantSurface : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACombatantSurface();
	void Init(class UCombatantAnimEvent* animEvent,class USkillTargets* targets);
	void ChangeMovement(class UCombatantMovement* movementBeforeUsingSkill);
	void Tick(float deltaTime)override;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStartAnimEvent, class UAnimSequence*, animSequence);

	UPROPERTY(BlueprintAssignable)
	FStartAnimEvent OnNeedToStartAnim;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	TObjectPtr<class UCombatantAnimEvent> mAnimEvent;
	TObjectPtr<class UCombatantMovement> mMovement;
	TObjectPtr<class USkillTargets> mTargets;
	FTimerHandle mTimerWhenExecuteSkill;
	bool mIsFinish = false;
	UFUNCTION()
	void BroadcastEvent(class UAnimSequence* animSequence);
};