// Fill out your copyright notice in the Description page of Project Settings.

#include "LightPistol.h"
#include "Particles/ParticleSystemComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Core/Public/Math/Vector.h"
#include "player_cpp.h"



// Sets default values
ALightPistol::ALightPistol(const FObjectInitializer& PCIP) : Super(PCIP)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	lifetime = 5;
	PrimaryActorTick.bCanEverTick = true;
	BeamStart = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Start"));
	BeamStart->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
	BeamStart->RelativeLocation = FVector(75.0f, 20.0f, 140.0f);
	BeamStart->SetHiddenInGame(true);

	ConstructorHelpers::FObjectFinder<UParticleSystem> Beam(TEXT("ParticleSystem'/Game/Particles/LaserBeamParticle.LaserBeamParticle'"));
	BeamParticle = PCIP.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("Beam"));

	if (Beam.Succeeded())
	{
		BeamParticle->Template = Beam.Object;
	}
	BeamParticle->bAutoActivate = true;
	BeamParticle->SetHiddenInGame(false);
	BeamParticle->SetupAttachment(BeamStart);
	//BeamParticle->SetBeamSourcePoint(1, FVector(999, 999, 999), 0);
	//BeamParticle->SetBeamTargetPoint(1, FVector(0, 0, 0), 0);
}

// Called when the game starts or when spawned
void ALightPistol::BeginPlay()
{
	Super::BeginPlay();
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("SPAWNED")));
	FHitResult OutHit;

	//FVector Start = HitBeam->GetComponentLocation();
	//FVector ForwardsVector = HitBeam->GetForwardVector();
	//FVector End = FVector((ForwardsVector * 10000.f) + Start);

	FVector Start = BeamStart->GetComponentLocation();
	FVector ForwardsVector = BeamStart->GetForwardVector();
	FVector End = FVector((ForwardsVector * 10000.f) + Start);
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);
	//does the linetrace
	if ((GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams) && CanShoot == true))
	{
		CanShoot = false;
		End = OutHit.Location;
		BeamParticle->SetFloatParameter("BeamDistance", FVector::Dist(Start, End));
		End = OutHit.Location;
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("You are hitting: %s"), *OutHit.GetActor()->GetName()));
		if (OutHit.GetActor()->GetClass() == Aplayer_cpp::StaticClass())
		{
			//if(player == owner)
			//continue;
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("HIT PLAYER")));
			Aplayer_cpp* Player = Cast<Aplayer_cpp>(OutHit.GetActor());
			AActor* owner = GetOwner();
			if (Player != nullptr && Player != owner)
			{
				Player->TakeDamage(2);
			}
		}
	}
	BeamParticle->ActivateSystem();
}

// Called every frame
void ALightPistol::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	lifetime -= 1;
	if (lifetime <= 0)
	{
		Destroy();
	}
}

