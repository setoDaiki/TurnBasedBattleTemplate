// Fill out your copyright notice in the Description page of Project Settings.


#include "Movement/NullMovement.h"

void UNullMovement::Go(class ACombatantSurface* combatant, TArray<class AActor*> targets) {
	EndGoing();
}


void UNullMovement::Return(class ACombatantSurface* combatant, TArray<class AActor*> targets) {
	EndReturning();
}