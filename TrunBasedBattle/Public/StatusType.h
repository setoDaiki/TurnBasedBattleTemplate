// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/*
  �X�e�[�^�X��ǉ�����ꍇ�ɂ�Final���O�ɒǉ����Ă��������B
  HP�X�e�[�^�X�̍폜�͋֎~
*/
UENUM(BlueprintType)
enum class EStatusType : uint8 {
	MaxHP,
	MaxMP,
	AttackPower,
	Defensive,
	Final
};
