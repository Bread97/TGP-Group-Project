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
	CharacterMovement->JumpZVelocity = 750;
	CharacterMovement->MaxWalkSpeed = 1200;
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
	CharacterMovement->Velocity.Z = 500;
	float GravityScale = CharacterMovement->GravityScale; CharacterMovement->GravityScale = 0.5;
	isWallRunning = true;	
}

//CALLED WHEN WALL RUN ENDS
void Aplayer_cpp::endWallRun()
{
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Blue, FString::Printf(TEXT("ENDING WALL RUN")));
	float GravityScale = CharacterMovement->GravityScale; CharacterMovement->GravityScale = 2;
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
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Purple, FString::Printf(TEXT("WALL NOT RIGHT")));
			wallOnRight = false;
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
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Purple, FString::Printf(TEXT("WALL NOT LEFT")));
			wallOnLeft = false;
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
				isWallRunning = false;
			}
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
		}
	}
	//DO THE WALL RUN
	{
		if (isWallRunning == true)
		{
			//doWallRun();
		}
	}
	//DO NOT DELETE THESE
	//wallOnLeft = false;
	//wallOnRight = false;
	//DO NOT DELETE THESE
	//IMPORTANTLINETRACES
}
