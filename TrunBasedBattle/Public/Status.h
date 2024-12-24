// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Containers/Map.h"
#include "Containers/Array.h"
#include "StatusType.h"
#include "Status.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRUNBASEDBATTLE_API UStatus : public UObject
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatus();

	void Init(EStatusType statusType,int32 maxValue,int32 defaultValue,class UBuffNotifier* buffNotifier);
	// use this method when debuf by pass the negative value
	void Buff(int32 value,uint32 numEffectTurn);
	void ResetBuff();
	void ResetDeBuff();
	void DefaultStatusUp(int32 value);
	int32 GetCurrentValue()const;
	int32 GetDefaultValue()const;
	int32 GetNumBuffedTime()const;
	EStatusType GetStatusType()const;

private:
	EStatusType mStatusType;
	int32 mMaxValue;
	int32 mCurrentValue;
	int32 mDefaultValue;
	int32 mBuffEffectTurn;
	int32 mNumOfBuffedTime = 0;
	TObjectPtr<class UBuffNotifier> mBuffNotifier;
};
