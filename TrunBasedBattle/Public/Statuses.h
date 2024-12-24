// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StatusType.h"
#include "Statuses.generated.h"

/**
 * 
 */
UCLASS()
class TRUNBASEDBATTLE_API UStatuses : public UObject
{
	GENERATED_BODY()
public:
	void Add(class UStatus* status);
	class UStatus* Get(EStatusType statusType);
	void Buff(EStatusType statusType, int32 buffValue, int32 numEffectTurn);
	int32 GetValue(EStatusType statusType);
	void ResetBuff(EStatusType statusType);
	void ResetDebuff(EStatusType statusType);
	void DefaultStatusUp(EStatusType statusType,int32 value);

private:
	TMap<EStatusType, UStatus*> mStatuses;
};
