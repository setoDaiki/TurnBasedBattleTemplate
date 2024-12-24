// Fill out your copyright notice in the Description page of Project Settings.


#include "Statuses.h"
#include "Status.h"
#include "Kismet/KismetSystemLibrary.h"

void UStatuses::Add(UStatus* status) {
	if (!status) return;
	mStatuses.Add(status->GetStatusType(),status);
}


UStatus* UStatuses::Get(EStatusType statusType) {
	UStatus* retVal = *mStatuses.Find(statusType);
	if (retVal) return retVal;
	UKismetSystemLibrary::PrintString(this,TEXT("Statuses.cpp 17 the statusType was not finded"));
	return nullptr;
}

void UStatuses::Buff(EStatusType statusType, int32 buffValue, int32 numEffectTurn) {
	UStatus* status = *mStatuses.Find(statusType);
	if (status) status->Buff(buffValue,numEffectTurn);
}

int32 UStatuses::GetValue(EStatusType statusType) {
	UStatus* status = *mStatuses.Find(statusType);
	if (status) return status->GetCurrentValue();
	return 1;
}

void UStatuses::ResetBuff(EStatusType statusType) {
	UStatus* status = *mStatuses.Find(statusType);
	if (status) status->ResetBuff();
}

void UStatuses::ResetDebuff(EStatusType statusType) {
	UStatus* status = *mStatuses.Find(statusType);
	if (status) status->ResetDeBuff();
}

void UStatuses::DefaultStatusUp(EStatusType statusType,int32 value) {
	UStatus* status = *mStatuses.Find(statusType);
	if (status) status->DefaultStatusUp(value);
}