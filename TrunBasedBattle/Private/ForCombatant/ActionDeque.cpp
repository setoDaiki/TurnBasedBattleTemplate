// Fill out your copyright notice in the Description page of Project Settings.


#include "ForCombatant/ActionDeque.h"
#include "ForUser/CombatantAction.h"

void UActionDeque::PushFront(class UCombatantAction* action) {
	if (!action) return;
	mActions.push_front(action);
}

void UActionDeque::PushBack(class UCombatantAction* action) {
	if (!action) return;
	mActions.push_back(action);
}

void UActionDeque::PopFront() {
	mActions.pop_front();
}

void UActionDeque::PopBack() {
	mActions.pop_back();
}

void UActionDeque::Clear() {
	mActions.clear();
}

void UActionDeque::ExecuteOne() {
	if (UCombatantAction* action = mActions.front()) {
		action->Execute();
	}
}

void UActionDeque::ExecuteAll() {
	for (auto action : mActions) {
		action->Execute();
	}
}