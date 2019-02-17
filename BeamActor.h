// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParticleDefinitions.h"
#include "BeamActor.generated.h"

UCLASS()
class FINGERGUNZ_API ABeamActor : public AActor
{
	ABeamActor(const FObjectInitializer& PCIP);
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABeamActor();
	int lifetime;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UStaticMeshComponent* BeamStart;
	UParticleSystemComponent* BeamParticle;
	
};
