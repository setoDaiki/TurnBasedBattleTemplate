// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <deque>
#include "UObject/NoExportTypes.h"
#include "ActionDeque.generated.h"

/**
 * 
 */
UCLASS()
class TRUNBASEDBATTLE_API UActionDeque : public UObject
{
	GENERATED_BODY()
public:
	void PushFront(class UCombatantAction* action);
	void PushBack(class UCombatantAction* action);
	void PopFront();
	void PopBack();
	void Clear();
	void ExecuteOne();
	void ExecuteAll();

private:
	std::deque<class UCombatantAction*> mActions;
};
