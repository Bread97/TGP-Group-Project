// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <vector>

#include "FGGameMode.h"
#include "Game Manager/PlayerInstance.h"

/**
 * 
 */
class FINGERGUNZ_API GameManager : AActor
{
public:
	GameManager();
	~GameManager();

	void InitGamemode(FGGameMode gamemode);

private:
	std::vector<PlayerInstance> players;
};
