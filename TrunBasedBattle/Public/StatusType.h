// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/*
  ステータスを追加する場合にはFinalより前に追加してください。
  HPステータスの削除は禁止
*/
UENUM(BlueprintType)
enum class EStatusType : uint8 {
	MaxHP,
	MaxMP,
	AttackPower,
	Defensive,
	Final
};
