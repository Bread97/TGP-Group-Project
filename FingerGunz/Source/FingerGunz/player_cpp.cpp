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
	DamageAmount = 1;
	ShootingDelay = 10;
	CharacterMovement->JumpZVelocity = 1000;
	CharacterMovement->MaxWalkSpeed = 1400;
	CharacterMovement->AirControl = 0.8;
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(0.0f, -11.5f, 130.f);
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
	FirstPersonCameraComponent->FieldOfView = 120;

	//StaticMesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("cube"));
	//StaticMesh->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Materials/Cube.Cube'")).Object);
	//StaticMesh->SetupAttachment(RootComponent);
	//StaticMesh->SetRelativeScale3D(FVector(0.6, 0.6, 2.1));
	//StaticMesh->SetActorHiddenInGame(true);

	PlayerStaticMesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("player"));
	PlayerStaticMesh->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Materials/PlayerMesh.PlayerMesh'")).Object);
	PlayerStaticMesh->SetupAttachment(RootComponent);
	PlayerStaticMesh->SetRelativeScale3D(FVector(0.3, 0.3, 0.3));
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
	PlayerInputComponent->BindAction("Beplayer1", IE_Pressed, this, &Aplayer_cpp::beplayer1);
	PlayerInputComponent->BindAction("Zoom", IE_Pressed, this, &Aplayer_cpp::StartZoom);
	PlayerInputComponent->BindAction("Zoom", IE_Released, this, &Aplayer_cpp::EndZoom);


	//axis events
	PlayerInputComponent->BindAxis("MoveForward", this, &Aplayer_cpp::moveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &Aplayer_cpp::moveRight);
	PlayerInputComponent->BindAxis("TurnRate", this, &Aplayer_cpp::turnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &Aplayer_cpp::lookUpAtRate);
	//KEYBOARD EVENTS
	//CONTROLLER EVENTS
	//action events
	PlayerInputComponent->BindAction("ControllerSpace", IE_Pressed, this, &Aplayer_cpp::Jump);
	PlayerInputComponent->BindAction("ControllerSpace", IE_Released, this, &Aplayer_cpp::StopJumping);
	PlayerInputComponent->BindAction("ControllerSpace", IE_Pressed, this, &Aplayer_cpp::tryWallRun);
	PlayerInputComponent->BindAction("ControllerSpace", IE_Pressed, this, &Aplayer_cpp::tryVault);
	PlayerInputComponent->BindAction("ControllerSpace", IE_Released, this, &Aplayer_cpp::tryStopWallRun);
	PlayerInputComponent->BindAction("ControllerShoot", IE_Pressed, this, &Aplayer_cpp::shoot);
	PlayerInputComponent->BindAction("ControllerShoot", IE_Released, this, &Aplayer_cpp::StopShooting);
	PlayerInputComponent->BindAction("ControllerZoom", IE_Pressed, this, &Aplayer_cpp::StartZoom);
	PlayerInputComponent->BindAction("ControllerZoom", IE_Released, this, &Aplayer_cpp::EndZoom);


	//axis events
	PlayerInputComponent->BindAxis("ControllerMoveForward", this, &Aplayer_cpp::moveForward);
	PlayerInputComponent->BindAxis("ControllerMoveRight", this, &Aplayer_cpp::moveRight);
	PlayerInputComponent->BindAxis("ControllerTurnRate", this, &Aplayer_cpp::turnAtRate);
	PlayerInputComponent->BindAxis("ControllerLookUpRate", this, &Aplayer_cpp::lookUpAtRate);
	//CONTROLLER EVENTS
}


// Called when the game starts or when spawned
void Aplayer_cpp::BeginPlay()
{
	Super::BeginPlay();
	
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
		if  (OutHit.GetActor()->GetClass() == Aplayer_cpp::StaticClass() )
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("HIT PLAYER")));
			AActor* ImpactActor = OutHit.GetActor();
			TSubclassOf<UDamageType> const ValidDamageTypeClass = TSubclassOf<UDamageType>(UDamageType::StaticClass());
			FDamageEvent DamageEvent(ValidDamageTypeClass);
			ImpactActor->TakeDamage(DamageAmount, DamageEvent, Aplayer_cpp::Controller, this);
		}
	}
	DrawDebugLine(GetWorld(), Start, End, FColor::Yellow, false, 1, 0, 1);
	IsShooting = true;
	//BROKEN AT THE MOMENT
	//UParticleSystemComponent* BeamComp = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), BeamEffect, this->GetActorLocation());
	//BeamComp->SetVectorParameter("BeamEnd", (OutHit.Actor != NULL) ? OutHit.ImpactPoint : End);
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("DOING BEAM EFFECT")));
	//BROKEN AT THE MOMENT
}
void Aplayer_cpp::StopShooting()
{
	IsShooting = false;
	ShootingDelay = 0;
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
	if (IsShooting == true)
	{
		if (ShootingDelay > 0)
		{
			ShootingDelay -= 1;
		}
		else
		{
			shoot();
			ShootingDelay = 10;
		}

	}
	//DO NOT DELETE THESE
	//wallOnLeft = false;
	//wallOnRight = false;
	//DO NOT DELETE THESE
	//IMPORTANTLINETRACES
}
