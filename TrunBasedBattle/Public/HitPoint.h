// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HitPoint.generated.h"

/**
 * 
 */
UCLASS()
class TRUNBASEDBATTLE_API UHitPoint : public UObject
{
	GENERATED_BODY()
public:
	void Initialize(int32 maxHitPoint, int32 currentHitPoint,class UHitPointChangeNotifier* notifier);
	void Damage(uint32 value);
	void Recover(uint32 value);
	bool IsDead();
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDeadEvent);
	UPROPERTY(EditAnywhere)
	FDeadEvent OnDead;

private:
	// �_���[�W��񕜎��̐U�镑���ϐ�����ɒǉ�
	int32 mCurrentHitPoint;
	int32 mMaxHitPoint;
	class UHitPointChangeNotifier* mNotifier;
};
