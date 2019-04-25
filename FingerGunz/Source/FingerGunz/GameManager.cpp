// Fill out your copyright notice in the Description page of Project Settings.

#include "GameManager.h"

AGameManager::AGameManager()
{
}

AGameManager::~AGameManager()
{
}

void AGameManager::AddKill(int playerID)
{
	players[playerID].totalKills++;
}

void AGameManager::AddDeath(int playerID)
{
	players[playerID].totalDeaths++;
}

int AGameManager::RegisterPlayer()
{
	players.Add(FPlayerStats());

	return players.Num() - 1;
}

