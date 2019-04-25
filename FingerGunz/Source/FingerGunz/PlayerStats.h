// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerStats.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FINGERGUNZ_API FPlayerStats
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int totalKills;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int totalDeaths;
};