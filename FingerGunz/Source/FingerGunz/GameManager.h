// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>
#include "PlayerStats.h"
#include "GameManager.generated.h"

/**
 * 
 */
UCLASS()
class FINGERGUNZ_API AGameManager : public AActor
{
public:
	AGameManager();
	~AGameManager();

	GENERATED_BODY()

	// Returns a player ID for the originating character
	UFUNCTION(BlueprintCallable, Category = "Game Manager")
	int RegisterPlayer();

	UFUNCTION(BlueprintCallable, Category = "Game Manager")
	void AddKill(int playerID);
	UFUNCTION(BlueprintCallable, Category = "Game Manager")
	void AddDeath(int playerID);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FPlayerStats> players;

private:
	int currentID;
	
};
