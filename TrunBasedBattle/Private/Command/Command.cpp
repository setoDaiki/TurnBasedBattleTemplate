// Fill out your copyright notice in the Description page of Project Settings.


#include "Command/Command.h"
#include "ForUser/CommandAction.h"
#include "Combatant.h"
#include "Kismet/KismetSystemLibrary.h"
#include "ForUser/Highlighter.h"
#include "Command/NoBehaviorDeferredCommand.h"
#include "Widget/SelectableWidget.h"
#include "Widget/HighlightableBorder.h"
#include "Widget/HighlightableImage.h"

UCommand::UCommand() {
	
}

void UCommand::Init(UCommandAction* action,int index) {
	if (!action) return;
	mCommandActions.Add(action);
	mIndex = index;
}

void UCommand::Init(UCommandAction* action) {
	if (action) mCommandActions.Add(action);
}

void UCommand::SetHighligheter(IHighlighter* highlighter) {
	if (!highlighter)return;
	mHighlighterWidget = highlighter;
}

void UCommand::AddCommandAction(UCommandAction* action) {
	if (!action) return;
	mCommandActions.Add(action);
}

void UCommand::Execute() {
	OnSelected.Broadcast();
	for (auto command : mCommandActions) {
		if (!command) continue;
		command->Execute();
	}
}

void UCommand::Undo() {
	for (auto command :  mCommandActions) {
		if (!command) continue;
		command->Undo();
	}
}

uint32 UCommand::GetIndex()const {
	return mIndex;
}


void UCommand::Highlight() {
	if (!mHighlighterWidget) return;
	mHighlighterWidget->Highlight();
}

void UCommand::RemoveHighlight() {
	if (!mHighlighterWidget) return;
	mHighlighterWidget->RemoveHighlight();
}

void UCommand::SetImageHighlighter(UHighlightableImage* image) {
	if (!image) return;
	mHighlighterWidget = image;
}

void UCommand::SetBorderHighlighter(UHighlightableBorder* border) {
	if (!border) return;
	mHighlighterWidget = border;
}