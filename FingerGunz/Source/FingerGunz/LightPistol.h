// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParticleDefinitions.h"
#include "LightPistol.generated.h"

UCLASS()
class FINGERGUNZ_API ALightPistol : public AActor
{
	ALightPistol(const FObjectInitializer& PCIP);
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALightPistol();
	int lifetime;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UStaticMeshComponent* GunMesh;
	UStaticMeshComponent* BeamStart;
	UParticleSystemComponent* BeamParticle;
	bool CanShoot;

};
