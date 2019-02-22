// Fill out your copyright notice in the Description page of Project Settings.

#include "player_cpp.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/UMG/Public/Components/ProgressBar.h"
#include "Particles/ParticleSystemComponent.h"
#include "BeamActor.h"
#include "LightPistol.h"

// Sets default values
Aplayer_cpp::Aplayer_cpp(const FObjectInitializer& PCIP) : Super(PCIP)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BaseTurnRate = 100.f;
	BaseLookUpRate = 100.f;
	wallJumpAmount = 500;
	vaultJumpAmount = 1200;
	Health = 5;
	Armor = 0;
	PistolDamageAmount = 3;
	ShootingDelay = 10;
	CharacterMovement->JumpZVelocity = 1000;
	CharacterMovement->MaxWalkSpeed = 1400;
	CharacterMovement->AirControl = 0.8;
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-5.0f, -5.0f, 155.f);
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
	FirstPersonCameraComponent->FieldOfView = 120;

	//StaticMesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("cube"));
	//StaticMesh->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Materials/Cube.Cube'")).Object);
	//StaticMesh->SetupAttachment(RootComponent);
	//StaticMesh->SetRelativeScale3D(FVector(0.6, 0.6, 2.1));
	//StaticMesh->SetActorHiddenInGame(true);

	PlayerStaticMesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("player"));
	PlayerStaticMesh->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Player/Player_Mesh_Armless.Player_Mesh_Armless'")).Object);
	PlayerStaticMesh->SetupAttachment(RootComponent);
	PlayerStaticMesh->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));

	GunStaticMesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("gun"));
	GunStaticMesh->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Player/Player_Mesh_Arm_1.Player_Mesh_Arm_1'")).Object);
	GunStaticMesh->SetupAttachment(FirstPersonCameraComponent);
	GunStaticMesh->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
										//					Height
	GunStaticMesh->RelativeLocation = FVector(160.0f, 20.0f, -50.0f);
	
	//PlayerParticleSystem = PCIP.CreateDefaultSubobject<UParticleSystem>(this, TEXT("beam"));
	//PlayerParticleSystem-(ConstructorHelpers::FObjectFinder<UParticleSystem>(TEXT("ParticleSystem'/Game/Particles/LaserBeamParticle.LaserBeamParticle'"), PlayerStaticMesh,FName("player"),FVector(0, 0, 64),FRotator(0, 0, 0),EAttachLocation::KeepRelativeOffset,false));
	//Spawn particle system
	ConstructorHelpers::FObjectFinder<UParticleSystem> Beam(TEXT("ParticleSystem'/Game/Particles/LaserBeamParticle.LaserBeamParticle'"));
	BeamParticle = PCIP.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("Beam"));

	if (Beam.Succeeded()) 
	{
		BeamParticle->Template = Beam.Object;
	}
	BeamParticle->bAutoActivate = true;
	BeamParticle->SetHiddenInGame(true);
	BeamParticle->SetupAttachment(GunStaticMesh);
	BeamParticle->ActivateSystem();
	//BeamParticle->SetBeamSourcePoint(0,FVector(9999, 9999, 9999),0);
	//BeamParticle->SetBeamEndPoint(0, FVector(1, 1, 1));
	//Beam.Target = FVector(0, 0, 0);

	//Spawn beam actor
	ConstructorHelpers::FObjectFinder<UBlueprint> BeamActorBP(TEXT("Blueprint'/Game/Particles/BeamActorBP.BeamActorBP'"));
	if (BeamActorBP.Object) {
		BeamActor_BP = (UClass*)BeamActorBP.Object->GeneratedClass;
	}
	//Spawn particle system
}


// Called to bind functionality to input
void Aplayer_cpp::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//KEYBOARD EVENTS
	//action events
	PlayerInputComponent->BindAction("Space", IE_Pressed, this, &Aplayer_cpp::Jump);
	PlayerInputComponent->BindAction("Space", IE_Released, this, &Aplayer_cpp::StopJumping);
	PlayerInputComponent->BindAction("Space", IE_Pressed, this, &Aplayer_cpp::tryWallRun);
	PlayerInputComponent->BindAction("Space", IE_Pressed, this, &Aplayer_cpp::tryVault);
	PlayerInputComponent->BindAction("Space", IE_Released, this, &Aplayer_cpp::tryStopWallRun);
	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &Aplayer_cpp::shoot);
	PlayerInputComponent->BindAction("Shoot", IE_Released, this, &Aplayer_cpp::StopShooting);
	PlayerInputComponent->BindAction("Zoom", IE_Pressed, this, &Aplayer_cpp::StartZoom);
	PlayerInputComponent->BindAction("Zoom", IE_Released, this, &Aplayer_cpp::EndZoom);


	//axis events
	PlayerInputComponent->BindAxis("MoveForward", this, &Aplayer_cpp::moveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &Aplayer_cpp::moveRight);
	PlayerInputComponent->BindAxis("TurnRate", this, &Aplayer_cpp::turnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &Aplayer_cpp::lookUpAtRate);
	//KEYBOARD EVENTS
}


// Called when the game starts or when spawned
void Aplayer_cpp::BeginPlay()
{
	Super::BeginPlay();
	BeamParticle->ActivateSystem();
}

void Aplayer_cpp::moveForward(float value)
{
	if (value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), value);
	}
}

void Aplayer_cpp::moveRight(float value)
{
	if (value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), value);
	}
}

void Aplayer_cpp::turnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void Aplayer_cpp::lookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

//TRYS TO WALLRUN AND ACTIVATES REQUIRED FUNCTIONS IF SUCCESSFULL
void Aplayer_cpp::tryWallRun()
{	
	//WALL RUN CODE
	if (canWallRun == true)
	{
		if (isWallRunning == false)
		{
			isWallRunning = true;
			doWallRun();
		}
		else
		{
			doWallJump();
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, FString::Printf(TEXT("DOING WALL JUMP")));
		}
	}
}

//may be needed later
void Aplayer_cpp::tryStopWallRun()
{	
	//WALL JUMP CODE
}

//DOES WALL RUN
void Aplayer_cpp::doWallRun()
{
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Blue, FString::Printf(TEXT("DOING WALL RUN")));
	CharacterMovement->Velocity.Z = 200;
	float GravityScale = CharacterMovement->GravityScale; CharacterMovement->GravityScale = 0.5;
	isWallRunning = true;	
}

//CALLED WHEN WALL RUN ENDS
void Aplayer_cpp::endWallRun()
{
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Blue, FString::Printf(TEXT("ENDING WALL RUN")));
	float GravityScale = CharacterMovement->GravityScale; CharacterMovement->GravityScale = 2.5;
}

//DOES WALL JUMP
void Aplayer_cpp::doWallJump()
{
	if (wallOnLeft == true)
	{
		FVector RightVector = FirstPersonCameraComponent->GetRightVector();
		FVector Direction = (RightVector * 500.f);
		CharacterMovement->Velocity.Z += 500;
		CharacterMovement->Velocity += Direction;
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, FString::Printf(TEXT("DOING LEFT WALL JUMP")));
	}
	else if (wallOnRight == true)
	{
		FVector RightVector = FirstPersonCameraComponent->GetRightVector();
		FVector Direction = (RightVector * -500.f);
		CharacterMovement->Velocity.Z += 500;
		CharacterMovement->Velocity += Direction;
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, FString::Printf(TEXT("DOING RIGHT WALL JUMP")));
	}
}

void Aplayer_cpp::tryVault()
{
	if (canVault == true)
	{
		if (isVaulting == false)
		{
			isVaulting = true;
			doVault();
		}
	}
}

void Aplayer_cpp::doVault()
{
	CharacterMovement->Velocity.Z = vaultJumpAmount;
	//FVector ForwardVector = FirstPersonCameraComponent->GetForwardVector();
	//FVector Direction = (ForwardVector * 500.f);
	//CharacterMovement->Velocity += Direction;
}

void Aplayer_cpp::endVault()
{
	//maybe going to add stuff here
}
//BROKEN
void Aplayer_cpp::shoot()
{
	//calculates the linetrace
	FHitResult OutHit;
	FVector Start = FirstPersonCameraComponent->GetComponentLocation();
	FVector ForwardsVector = FirstPersonCameraComponent->GetForwardVector();
	FVector End = FVector((ForwardsVector * 10000.f) + Start);
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);
	//does the linetrace
	if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams)) 
	{
		End = OutHit.Location;
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("You are hitting: %s"), *OutHit.GetActor()->GetName()));
		if (OutHit.GetActor()->GetClass() == Aplayer_cpp::StaticClass())
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("HIT PLAYER")));
			AActor* ImpactActor = OutHit.GetActor();
			TSubclassOf<UDamageType> const ValidDamageTypeClass = TSubclassOf<UDamageType>(UDamageType::StaticClass());
			FDamageEvent DamageEvent(ValidDamageTypeClass);
			ImpactActor->TakeDamage(PistolDamageAmount, DamageEvent, Aplayer_cpp::Controller, this);
		}
	}
	//DrawDebugLine(GetWorld(), Start, End, FColor::Yellow, false, 1, 0, 1);
	IsShooting = true;
	//BeamParticle->SetHiddenInGame(false);
	//BROKEN AT THE MOMENT
	//UParticleSystemComponent* BeamComp = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), BeamEffect, this->GetActorLocation());
	//BeamComp->SetVectorParameter("BeamEnd", (OutHit.Actor != NULL) ? OutHit.ImpactPoint : End);
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("DOING BEAM EFFECT")));
	//BROKEN AT THE MOMENT
	//Spawns c++ beam actor
	FActorSpawnParameters SpawnInfo;
	GetWorld()->SpawnActor<ALightPistol>(GunStaticMesh->GetComponentLocation(), FirstPersonCameraComponent->GetComponentRotation(), SpawnInfo);
	//Spawns c++ beam actor
}

void Aplayer_cpp::StopShooting()
{
	IsShooting = false;
	ShootingDelay = 0;
	//BeamParticle->SetHiddenInGame(true);
}
//BROKEN

float Aplayer_cpp::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	//HOW MUCH DAMAGE?
	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	if (ActualDamage > 0.f)
	{
		Health -= ActualDamage;
		//"KILLS" PLAYER 
		if (Health <= 0.f)
		{
			this->SetActorLocation(FVector(0, 0, 5000));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("YOU DIED")));
			Health = 5;
		}
	}
	return ActualDamage;
}

void Aplayer_cpp::StartZoom()
{
	BaseTurnRate = 25.f;
	BaseLookUpRate = 25.f;
	FirstPersonCameraComponent->FieldOfView = 50;
}

void Aplayer_cpp::EndZoom()
{
	BaseTurnRate = 100.f;
	BaseLookUpRate = 100.f;
	FirstPersonCameraComponent->FieldOfView = 120;
}


void Aplayer_cpp::beplayer1()
{
	//not needed at the moment but might be usefull for testing
}

// Called every frame
void Aplayer_cpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//IMPORTANTLINETRACES
	//RIGHT LINETRACE
	{
		//calculates the linetrace
		FHitResult OutHit;
		FVector Start = FirstPersonCameraComponent->GetComponentLocation();
		FVector RightVector = FirstPersonCameraComponent->GetRightVector();
		FVector End = ((RightVector * 100.f) + Start);
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(this);
		//does the linetrace
		if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams))
		{
			//outputs info (debug build only)
			if (OutHit.bBlockingHit)
			{
				GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("WALL RIGHT")));
				wallOnRight = true;
			}
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Purple, FString::Printf(TEXT("WALL NOT RIGHT")));
			wallOnRight = false;
		}
	}
	//LEFT LINETRACE
	{
		//calculates the linetrace
		FHitResult OutHit;
		FVector Start = FirstPersonCameraComponent->GetComponentLocation();
		FVector RightVector = FirstPersonCameraComponent->GetRightVector();
		FVector End = ((RightVector * -100.f) + Start);
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(this);
		//does the linetrace
		if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams))
		{
			//outputs info (debug build only)
			if (OutHit.bBlockingHit)
			{
				GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("WALL LEFT")));
				wallOnLeft = true;
			}
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Purple, FString::Printf(TEXT("WALL NOT LEFT")));
			wallOnLeft = false;
		}
	}
	//DOWNWARDS LINETRACE, CHECKS TO SEE IF PLAYER NIS ON THE FLOOR
	{
		//calculates the linetrace
		FHitResult OutHit;
		FVector Start = FirstPersonCameraComponent->GetComponentLocation();
		FVector UpVector = FirstPersonCameraComponent->GetUpVector();
		FVector End = FVector(Start.X, Start.Y, Start.Z - 250);
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(this);
		//does the linetrace
		if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams))
		{
			if (OutHit.bBlockingHit)
			{
				GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("ON FLOOR")));
				isWallRunning = false;
				isVaulting = false;
				canVault = false;
			}
		}
	}
	//FORWARDS LINETRACE, CHECKS TO SEE IF THE PLAYER CAN VAULT
	{
		//calculates the linetrace
		FHitResult OutHit;
		FVector Start = FirstPersonCameraComponent->GetComponentLocation();
		FVector ForwardsVector = FirstPersonCameraComponent->GetForwardVector();
		FVector End = FVector((ForwardsVector * 300.f) + Start);
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(this);
		//does the linetrace
		if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams))
		{
			if (OutHit.bBlockingHit)
			{
				GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Green, FString::Printf(TEXT("CAN VAULT")));
				canVault = true;
			}
		}
		else
		{
			canVault = false;
			GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Green, FString::Printf(TEXT("CAN'T VAULT")));
		}
	}
	{
		//ACTIVATES WALLRUNS AND CHECKS TO SEE IF PLAYER CAN WALLRUN
		if (wallOnRight == false && wallOnLeft == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("CANT WALL RUN")));
			canWallRun = false;
			isWallRunning = false;
			endWallRun();
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("CAN WALL RUN")));
			canWallRun = true;
			if (canWallRun == true)
			{
				if (isWallRunning == false)
				{
					isWallRunning = true;
					doWallRun();
				}
			}
		}
	}
	//DO THE WALL RUN
	{
		if (isWallRunning == true)
		{
			//doWallRun();
		}
	}
	if (this->GetActorLocation().Z <= -1000)
	{
		this->SetActorLocation(FVector(0, 0, 1000));
	}
	if (Health > 5)
	{
		Health = 5;
	}
	//if (IsShooting == true)
	//{
	//	if (ShootingDelay > 0)
	//	{
	//		ShootingDelay -= 1;
	//	}
	//	else
	//	{
	//		shoot();
	//		ShootingDelay = 10;
	//	}
	//
	//}
	//DO NOT DELETE THESE
	//wallOnLeft = false;
	//wallOnRight = false;
	//DO NOT DELETE THESE
	//IMPORTANTLINETRACES
}
