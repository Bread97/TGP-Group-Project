//Parent to all weapon classes. Should be called by all weapons.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParticleDefinitions.h"
#include "LightPistol.generated.h"

UCLASS()
class FINGERGUNZ_API AWeaponMaster : public AActor
{
	AWeaponMaster(const FObjectInitializer& PCIP);
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeaponMaster();
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