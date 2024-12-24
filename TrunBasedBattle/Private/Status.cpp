// Fill out your copyright notice in the Description page of Project Settings.


#include "Status.h"
#include "BuffNotifier/BuffNotifier.h"
#include "Kismet/KismetSystemLibrary.h"
#include <cassert>

// Sets default values for this component's properties
UStatus::UStatus()
{
	
}

void UStatus::Init(EStatusType statusType,int32 maxValue,int32 defaultValue,UBuffNotifier* buffNotifier) {
	if (buffNotifier) mBuffNotifier = buffNotifier;
	mMaxValue = maxValue;
	mDefaultValue = defaultValue;
	mCurrentValue = mDefaultValue;
	mStatusType = statusType;
}

void UStatus::Buff(int32 value,uint32 effectTurn) {
	if (value > 0) {
		mNumOfBuffedTime += 1;
	}
	else {
		mNumOfBuffedTime -= 1;
	}
	mCurrentValue += value;
	if (!mBuffNotifier) return;
	mBuffNotifier->Notify(value);
}

EStatusType UStatus::GetStatusType()const {
	return mStatusType;
}

int32 UStatus::GetCurrentValue()const {
	return mCurrentValue;
}

void UStatus::DefaultStatusUp(int32 value){
	mDefaultValue += value;
}

int32 UStatus::GetDefaultValue()const {
	return mDefaultValue;
}

int32 UStatus::GetNumBuffedTime()const {
	return mNumOfBuffedTime;
}

void UStatus::ResetBuff() {
	if (mNumOfBuffedTime > 0) {
		mNumOfBuffedTime = 0;
		mCurrentValue = mDefaultValue;
	}
}

void UStatus::ResetDeBuff() {
	if (mNumOfBuffedTime < 0) {
		mNumOfBuffedTime = 0;
		mCurrentValue = mDefaultValue;
	}
}