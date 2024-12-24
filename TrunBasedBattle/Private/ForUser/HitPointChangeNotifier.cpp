// Fill out your copyright notice in the Description page of Project Settings.


#include "ForUser/HitPointChangeNotifier.h"
#include "Kismet/KismetSystemLibrary.h"

void UHitPointChangeNotifier::NotifyRecovery_Implementation(int32 recoverVal) {
	UKismetSystemLibrary::PrintString(nullptr,FString::Printf(TEXT("recover value = %d"),recoverVal));
}

void UHitPointChangeNotifier::NotifyDamage_Implementation(int32 damageVal) {
	UKismetSystemLibrary::PrintString(nullptr,FString::Printf(TEXT("damege = %d"),damageVal));
}