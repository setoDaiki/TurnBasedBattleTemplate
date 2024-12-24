// Fill out your copyright notice in the Description page of Project Settings.


#include "HitPoint.h"
#include "ForUser/HitPointChangeNotifier.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

void UHitPoint::Initialize(int32 maxHitPoint,int32 currentHitPoint,UHitPointChangeNotifier* notifier) {
	mMaxHitPoint = maxHitPoint;
	mCurrentHitPoint = currentHitPoint;
	if (notifier) mNotifier = notifier;
}

void UHitPoint::Recover(uint32 val) {
	mNotifier->NotifyRecovery(val);
	mCurrentHitPoint += val;
	mCurrentHitPoint = UKismetMathLibrary::Min(mMaxHitPoint,mCurrentHitPoint);
}

void UHitPoint::Damage(uint32 val) {
	mNotifier->NotifyDamage(val);
	mCurrentHitPoint -= val;
	if (mCurrentHitPoint <= 0) {
		mCurrentHitPoint = 0;
		OnDead.Broadcast();
	}
}

bool UHitPoint::IsDead() {
	if (mCurrentHitPoint <= 0) return true;
	return false;
}