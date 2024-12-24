// Fill out your copyright notice in the Description page of Project Settings.


#include "ForCombatant/SkillManager.h"
#include "Skill.h"
#include "Widget/EnemySelectorWidget.h"
#include "Widget/SkillSelectorWidget.h"
#include "Combatant.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Command/Command.h"
#include "Command/DeferredActionCommand.h"
#include "Command/ToNextWidgetCommand.h"
#include "CombatantAction/UsingSkillAction.h"
#include "ForCombatant/CombatantAnimEvent.h"

// Sets default values for this component's properties
USkillManager::USkillManager()
{
}

void USkillManager::Init(UCombatantAnimEvent* animEvent) {
	mAnimEvent = animEvent;
}

void USkillManager::Add(USkill* skill) {
	mSkills.Add(skill);
	skill->OnStartUsingSkill.AddLambda([this](class UAnimSequence* anim) {mAnimEvent->OnNeedToBeginAnim.Broadcast(anim); });
	skill->OnEndUsingSkill.AddDynamic(this,&USkillManager::BroadCastEndUsingSkill);
}

USkillSelectorWidget* USkillManager::CreateSkillWidget(UWorld* world,UEnemySelectorWidget* enemySelector,class UActionDeque* actionDeque) {
	USkillSelectorWidget* widget = CreateWidget<USkillSelectorWidget>(world);
	if (!widget) {
		UKismetSystemLibrary::PrintString(this,TEXT("nazenanoka"));
		return nullptr;
	}
	TArray<UCommand*> commands;
	commands.Reserve(mSkills.Num());
	for (auto skill : mSkills) {
		UToNextWidgetCommand* commandAction = NewObject<UToNextWidgetCommand>(this);
		commandAction->Init(widget, enemySelector);
		UUsingSkillAction* skillAction = NewObject<UUsingSkillAction>(this);
		skillAction->Init(skill);
		UDeferredActionCommand* defferdActionCommand = NewObject<UDeferredActionCommand>(this);
		defferdActionCommand->Init(skillAction,actionDeque);
		UCommand* command = NewObject<UCommand>(this);
		command->Init(commandAction);
		command->AddCommandAction(defferdActionCommand);
		command->SetText(skill->GetName());
		commands.Add(command);
	}
	widget->Init(commands);
	widget->AddToViewport();
	return widget;
}

void USkillManager::BroadCastSkillUsing(class UAnimSequence* anim) {
	mAnimEvent->OnNeedToBeginAnim.Broadcast(anim);
}

void USkillManager::BroadCastEndUsingSkill() {
	mAnimEvent->OnEndUsingSkill.Broadcast();
}