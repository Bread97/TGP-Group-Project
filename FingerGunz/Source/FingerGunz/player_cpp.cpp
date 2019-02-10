// Fill out your copyright notice in the Description page of Project Settings.

#include "player_cpp.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
Aplayer_cpp::Aplayer_cpp()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
	wallJumpAmount = 500;
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f);
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
}

// Called to bind functionality to input
void Aplayer_cpp::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//action events
	PlayerInputComponent->BindAction("Space", IE_Pressed, this, &Aplayer_cpp::Jump);
	PlayerInputComponent->BindAction("Space", IE_Released, this, &Aplayer_cpp::StopJumping);
	PlayerInputComponent->BindAction("Space", IE_Pressed, this, &Aplayer_cpp::tryWallRun);
	PlayerInputComponent->BindAction("Space", IE_Released, this, &Aplayer_cpp::tryStopWallRun);


	//axis events
	PlayerInputComponent->BindAxis("MoveForward", this, &Aplayer_cpp::moveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &Aplayer_cpp::moveRight);
	PlayerInputComponent->BindAxis("TurnRate", this, &Aplayer_cpp::turnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &Aplayer_cpp::lookUpAtRate);
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

void Aplayer_cpp::tryWallRun()
{	
	//RIGHT WALL RUN CODE
	//get right vector
}

void Aplayer_cpp::tryStopWallRun()
{	
	//RIGHT WALL JUMP CODE
	//get right vector
}


void Aplayer_cpp::doWallRun(bool left, bool right)
{
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("TOUCHING WALL ON RIGHT")));
	//CharacterMovement->Velocity.Z = 250;
	//float GravityScale = CharacterMovement->GravityScale; CharacterMovement->GravityScale = 0.5;
	//isWallRunning = true;
}

// Called every frame
void Aplayer_cpp::Tick(float DeltaTime)
{
	//IMPORTANTLINETRACES
	//RIGHT LINETRACE
	{
		FHitResult OutHit;
		FVector Start = FirstPersonCameraComponent->GetComponentLocation();
		FVector RightVector = FirstPersonCameraComponent->GetRightVector();
		FVector End = ((RightVector * 100.f) + Start);
		FCollisionQueryParams CollisionParams;

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
	}
	//LEFT LINETRACE
	{
		FHitResult OutHit;
		FVector Start = FirstPersonCameraComponent->GetComponentLocation();
		FVector RightVector = FirstPersonCameraComponent->GetRightVector();
		FVector End = ((RightVector * -100.f) + Start);
		FCollisionQueryParams CollisionParams;

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
	}
	//DOWNWARDS LINETRACE
	{
		Super::Tick(DeltaTime);
		FHitResult OutHit;
		FVector Start = FirstPersonCameraComponent->GetComponentLocation();
		FVector UpVector = FirstPersonCameraComponent->GetUpVector();
		FVector End = FVector(Start.X, Start.Y, Start.Z - 250);
		FCollisionQueryParams CollisionParams;

		//does the linetrace
		if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams))
		{
			if (OutHit.bBlockingHit)
			{
				GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("ON FLOOR")));
			}
		}
	}
	{
		if (wallOnRight == false && wallOnLeft == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("CANT WALL RUN")));
			canWallRun = false;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("CAN WALL RUN")));
			canWallRun = true;
		}
	}
	//DO NOT DELETE THESE
	wallOnLeft = false;
	wallOnRight = false;
	//DO NOT DELETE THESE
	//IMPORTANTLINETRACES
}
