#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParticleDefinitions.h"
#include "Shotgun.generated.h"

UCLASS()
class FINGERGUNZ_API AShotgun : public AActor
{
	AShotgun(const FObjectInitializer& PCIP);
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AShotgun();
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
