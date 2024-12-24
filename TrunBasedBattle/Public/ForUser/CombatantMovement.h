// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CombatantMovement.generated.h"

/**
 * 
 */
UCLASS()
class TRUNBASEDBATTLE_API UCombatantMovement : public UObject
{
	GENERATED_BODY()
public:
	void Update(class ACombatantSurface* surface,TArray<class AActor*> targets);
	bool IsFinished();
	void ToReturnMovement();
	void ToGoMovement();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFinishMovement);
	UPROPERTY(BlueprintAssignable)
	FFinishMovement OnFinishedGoing;
	FFinishMovement OnFinishedReturning;

protected:
	FVector GetCombatantFirstLocation();
	void EndGoing();
	void EndReturning();

private:
	virtual void Go(class ACombatantSurface* combatant,TArray<class AActor*> targets);
	virtual void Return(class ACombatantSurface* combatant,TArray<class AActor*> targets);
	FVector mFirstLocation;
	bool mIsFinishedMovement = false;
	bool mIsFirstMovement = true;
	bool mIsReturning = false;
	int i = 0;
};
