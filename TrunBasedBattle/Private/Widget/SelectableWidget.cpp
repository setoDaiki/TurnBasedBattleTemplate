// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/SelectableWidget.h"
#include "Components/Widget.h"
#include "Blueprint/WidgetTree.h"
#include "Command/Command.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "TurnBasePlayerController.h"
#include "ForUser/Highlighter.h"
#include "ForUser/SkillAction.h"

void USelectableWidget::NativeConstruct()
{
	mFocusCommandIndex = 0;
	if (!WidgetTree) return;
	TArray<UWidget*> widgets;
	WidgetTree->GetAllWidgets(widgets);
	int i = 0;
	for (auto widget : widgets) {
		UCommand* command = Cast<UCommand>(widget);
		if (!command) continue;
		mSelectableUIs.Add(command);
		UPanelWidget* panelWidget = widget->GetParent();
		if (IHighlighter* highlighter = Cast<IHighlighter>(panelWidget)) {
			command->SetHighligheter(highlighter);
		}
	}
	if (mSelectableUIs.IsEmpty()) return;
	mSelectableUIs[0]->Highlight();
}

void USelectableWidget::SortCommands() {
	auto sortLambda = [](const UCommand& command1, const UCommand& command2) {
		return command1.GetIndex() < command2.GetIndex();
		};
	mSelectableUIs.StableSort(sortLambda);
}

void USelectableWidget::Add(UCommand* widget) {
	if (mSelectableUIs.Contains(widget)) return;
	mSelectableUIs.Add(widget);
	SortCommands();
}

void USelectableWidget::Remove(UCommand* command) {
	mSelectableUIs.Remove(command);
	mFocusCommandIndex = 0;
}

void USelectableWidget::ClearCommands() {
	mSelectableUIs.Empty();
	if (!WidgetTree) return;
	TArray<UWidget*> widgets;
	WidgetTree->GetAllWidgets(widgets);
	TArray<UCommand*> commands;
	TArray<UWidget*> highlighters;
	for (auto widget : widgets) {
		UCommand* command = Cast<UCommand>(widget);
		if (!command) continue;
		commands.Add(command);
		UPanelWidget* panelWidget = widget->GetParent();
		if (IHighlighter* highlighter = Cast<IHighlighter>(panelWidget)) {
			highlighters.Add(panelWidget);
		}
	}
	for (auto highlighter : highlighters) {
		highlighter->RemoveFromParent();
	}
	for (auto command : commands) {
		command->RemoveFromParent();
	}
	mFocusCommandIndex = 0;
}

void USelectableWidget::ProcessSelectedUI(uint32 processNum) {
	if (mSelectableUIs.IsEmpty()) return;
	if (mSelectableUIs[mFocusCommandIndex]) {
		mSelectableUIs[mFocusCommandIndex]->RemoveHighlight();
	}
	mFocusCommandIndex += processNum;
	int32 arrayNum = mSelectableUIs.Num();
	if (mFocusCommandIndex >= arrayNum) {
		mFocusCommandIndex = 0;
	}
	if (mFocusCommandIndex < 0) {
		mFocusCommandIndex = arrayNum - 1;
	}
	mSelectableUIs[mFocusCommandIndex]->Highlight();
}

void USelectableWidget::Determained() {
	if (mSelectableUIs.IsEmpty()) return;
	if (!mSelectableUIs[mFocusCommandIndex]) return;
	mSelectableUIs[mFocusCommandIndex]->Execute();
	OnSelected.Broadcast();
}

void USelectableWidget::Canceled() {
	if (!mMadeMeWidget) return;
	mMadeMeWidget->UndoCommands();
}

void USelectableWidget::UndoCommands() {
	if (!mSelectableUIs[mFocusCommandIndex]) return;
	mSelectableUIs[mFocusCommandIndex]->Undo();
}

UCommand* USelectableWidget::GetSelectedUI() {
	if (!mSelectableUIs[mFocusCommandIndex]) return nullptr;
	return mSelectableUIs[mFocusCommandIndex];
}


void USelectableWidget::ToSelectableState() {
	ATurnBasePlayerController* controller = Cast<ATurnBasePlayerController>(UGameplayStatics::GetPlayerController(GetWorld(),0));
	SetVisibility(ESlateVisibility::Visible);
	controller->ChangeOperatingWidget(this);
}

void USelectableWidget::SetPrevWidget(USelectableWidget* creater) {
	mMadeMeWidget = creater;
}