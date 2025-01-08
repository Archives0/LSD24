// Fill out your copyright notice in the Description page of Project Settings.


#include "LSD.h"

void ULSD::AddToInventory(FLSDItem newItem)
{
	playerItems.Add(newItem);
}

void ULSD::ChangeStoryStage(EGameStage newStage)
{
	storyStage = newStage;
}

void ULSD::AddNewQuest(FLSDQuest newQuest)
{
	questLog.Add(newQuest);
}

void ULSD::CompleteQuest(FLSDQuest newQuest)
{
	if (questLog.Contains(newQuest))
	{
		int questIndex{};
		questLog.Find(newQuest, questIndex);
		questLog[questIndex].complete = true;
	}
}
