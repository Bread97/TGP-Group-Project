// Fill out your copyright notice in the Description page of Project Settings.

#include "ShotGun.h"
#include "Particles/ParticleSystemComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Core/Public/Math/Vector.h"
#include "player_cpp.h"



// Sets default values
AShotgun::AShotgun(const FObjectInitializer& PCIP) : Super(PCIP)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	lifetime = 50;
	PrimaryActorTick.bCanEverTick = true;
	BeamStart = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Start"));
	BeamStart->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Player/Player_Mesh_Arm_1.Player_Mesh_Arm_1'")).Object);
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
void AShotgun::BeginPlay()
{
	Super::BeginPlay();
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("SPAWNED")));
	FHitResult OutHit;
	FVector Start = BeamStart->GetComponentLocation();
	FVector ForwardsVector = BeamStart->GetForwardVector();
	FVector End = FVector((ForwardsVector * 10000.f) + Start);
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);
	//does the linetrace
	if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams))
	{
		End = OutHit.Location;
		BeamParticle->SetFloatParameter("BeamDistance", FVector::Dist(Start, End));
		End = OutHit.Location;
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("You are hitting: %s"), *OutHit.GetActor()->GetName()));
		if (OutHit.GetActor()->GetClass() == Aplayer_cpp::StaticClass())
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("HIT PLAYER")));
			Aplayer_cpp* Player = Cast<Aplayer_cpp>(OutHit.GetActor());
			if (Player != nullptr)
			{
				Player->TakeDamage(3);
			}
		}
	}
	BeamParticle->ActivateSystem();
}

// Called every frame
void AShotgun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	lifetime -= 1;
	if (lifetime <= 0)
	{
		Destroy();
	}
}

