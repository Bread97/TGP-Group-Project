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

//#include "BeamActor.h"
//#include "LightPistol.h"
//#include "HeavyPistol.h"
//#include "ShotGun.h"

// Sets default values
Aplayer_cpp::Aplayer_cpp(const FObjectInitializer& PCIP) : Super(PCIP)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BaseTurnRate = 100.f;
	BaseLookUpRate = 100.f;
	wallJumpAmount = 500;
	vaultJumpAmount = 1200;
	//Health = 5;
	//Armor = 0;
	PistolDamageAmount = 3;
	ShootingDelay = 10;
	CharacterMovement->JumpZVelocity = 1000;
	CharacterMovement->MaxWalkSpeed = 1400;
	CharacterMovement->AirControl = 0.8;
	CurrentWeapon = 1;

	GetCapsuleComponent()->SetRelativeScale3D(FVector(1.5, 1.5, 1.5));

	//Create First Person Camera Component
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(0.0f, 0.0f, 80.f);
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
	FirstPersonCameraComponent->FieldOfView = 120;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////****LOAD IN PLAYER MESHES****/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/*
	//Renders the Gun for the player only
	GunMesh = PCIP.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("GunMesh"));
	GunMesh->SetSkeletalMesh(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("SkeletalMesh'/Game/Player/Meshes/Weapon_Meshes/Meshes_And_Animations/character_arms_standard.character_arms_standard'")).Object);
	GunMesh->SetOnlyOwnerSee(true);
	GunMesh->SetupAttachment(FirstPersonCameraComponent);
	GunMesh->SetRelativeScale3D(FVector(0.30, 0.30, 0.30));
	GunMesh->RelativeLocation = FVector(10.0f, 20.0f, -120.0f);


	LightGunMesh = PCIP.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("LightGun"));
	LightGunMesh->SetSkeletalMesh(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("SkeletalMesh'/Game/Player/Meshes/Weapon_Meshes/Meshes_And_Animations/character_arms_standard.character_arms_standard'")).Object);



	HeavyGunMesh = PCIP.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("HeavyGun"));
	HeavyGunMesh->SetSkeletalMesh(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("SkeletalMesh'/Game/Player/Meshes/Weapon_Meshes/Meshes_And_Animations/character_arms_Heavy.character_arms_Heavy'")).Object);



	ShotgunMesh = PCIP.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("Shotgun"));
	ShotgunMesh->SetSkeletalMesh(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("SkeletalMesh'/Game/Player/Meshes/Weapon_Meshes/Meshes_And_Animations/character_arms_shotgun.character_arms_shotgun'")).Object);


	//Loads the Beam Particles
	ConstructorHelpers::FObjectFinder<UParticleSystem> Beam(TEXT("ParticleSystem'/Game/Particles/LaserBeamParticle.LaserBeamParticle'"));
	BeamParticle = PCIP.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("Beam"));

	if (Beam.Succeeded()) 
	{
		BeamParticle->Template = Beam.Object;
	}
	BeamParticle->bAutoActivate = true;
	BeamParticle->SetHiddenInGame(true);
	BeamParticle->SetupAttachment(LightGunMesh);
	BeamParticle->ActivateSystem();

	//Spawn beam actor
	ConstructorHelpers::FObjectFinder<UBlueprint> BeamActorBP(TEXT("Blueprint'/Game/Particles/BeamActorBP.BeamActorBP'"));
	if (BeamActorBP.Object) 
	{
		BeamActor_BP = (UClass*)BeamActorBP.Object->GeneratedClass;
	}
	*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}


// Called to bind functionality to input
void Aplayer_cpp::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	///////Input Events///////
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//action events
	PlayerInputComponent->BindAction("Space", IE_Pressed, this, &Aplayer_cpp::Jump);
	PlayerInputComponent->BindAction("Space", IE_Released, this, &Aplayer_cpp::StopJumping);
	PlayerInputComponent->BindAction("Space", IE_Pressed, this, &Aplayer_cpp::tryWallRun);
	PlayerInputComponent->BindAction("Space", IE_Pressed, this, &Aplayer_cpp::tryVault);
	PlayerInputComponent->BindAction("Space", IE_Released, this, &Aplayer_cpp::tryStopWallRun);
	//PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &Aplayer_cpp::shoot);
	//PlayerInputComponent->BindAction("Shoot", IE_Released, this, &Aplayer_cpp::StopShooting);
	PlayerInputComponent->BindAction("Zoom", IE_Pressed, this, &Aplayer_cpp::StartZoom);
	PlayerInputComponent->BindAction("Zoom", IE_Released, this, &Aplayer_cpp::EndZoom);

	//axis events
	PlayerInputComponent->BindAxis("MoveForward", this, &Aplayer_cpp::moveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &Aplayer_cpp::moveRight);
	PlayerInputComponent->BindAxis("TurnRate", this, &Aplayer_cpp::turnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &Aplayer_cpp::lookUpAtRate);

	//D-Pad Events
	/*PlayerInputComponent->BindAction("ChangeWeaponUp", IE_Pressed, this, &Aplayer_cpp::ChangeUp);
	PlayerInputComponent->BindAction("ChangeWeaponDown", IE_Pressed, this, &Aplayer_cpp::ChangeDown);
	PlayerInputComponent->BindAction("ChangeWeaponLeft", IE_Pressed, this, &Aplayer_cpp::ChangeLeft);
	PlayerInputComponent->BindAction("ChangeWeaponRight", IE_Pressed, this, &Aplayer_cpp::ChangeRight);
	*/
}

//Handle damage taken from incoming attacks
/*
void Aplayer_cpp::TakeDamage(float Damage)
{
	if (Health > 0)
	{
		Health -= Damage;
		if (Health < 1)
		{
			this->SetActorLocation(FVector(0, 0, 5000));
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("YOU DIED")));
			Health = 5;
		}
	}
	else
	{
		this->SetActorLocation(FVector(0, 0, 5000));
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("YOU DIED")));
		Health = 5;
	}
	return;
}
*/


// Called when the game starts or when spawned
void Aplayer_cpp::BeginPlay()
{
	Super::BeginPlay();
	//BeamParticle->ActivateSystem();
}

/////////////////Handle player movement//////////////////////
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
			//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, FString::Printf(TEXT("DOING WALL JUMP")));
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
	//GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Blue, FString::Printf(TEXT("DOING WALL RUN")));
	CharacterMovement->Velocity.Z = 200;
	float GravityScale = CharacterMovement->GravityScale; CharacterMovement->GravityScale = 0.5;
	isWallRunning = true;	
}

//CALLED WHEN WALL RUN ENDS
void Aplayer_cpp::endWallRun()
{
	//GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Blue, FString::Printf(TEXT("ENDING WALL RUN")));
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
		//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, FString::Printf(TEXT("DOING LEFT WALL JUMP")));
	}
	else if (wallOnRight == true)
	{
		FVector RightVector = FirstPersonCameraComponent->GetRightVector();
		FVector Direction = (RightVector * -500.f);
		CharacterMovement->Velocity.Z += 500;
		CharacterMovement->Velocity += Direction;
		//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, FString::Printf(TEXT("DOING RIGHT WALL JUMP")));
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
/*
void Aplayer_cpp::ChangeUp()
{
	CurrentWeapon = 1;
	GunMesh->SetSkeletalMesh(LightGunMesh->SkeletalMesh);
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("Current Weapon: LPistol")));
}
void Aplayer_cpp::ChangeLeft()
{
	CurrentWeapon = 2;
	GunMesh->SetSkeletalMesh(HeavyGunMesh->SkeletalMesh);
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("Current Weapon: HPistol")));
}
void Aplayer_cpp::ChangeRight()
{
	CurrentWeapon = 3;
	GunMesh->SetSkeletalMesh(ShotgunMesh->SkeletalMesh);
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("Current Weapon: Shotgun")));
}
void Aplayer_cpp::ChangeDown()
{
	CurrentWeapon = 4;
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("Current Weapon: Rocket Launcher")));
}
*/

/*
//Handle Weapon Switching
void Aplayer_cpp::shoot()
{
	FActorSpawnParameters SpawnInfo;
	switch (CurrentWeapon)
	{
	case 1 :
		GetWorld()->SpawnActor<ALightPistol>(GunMesh->GetComponentLocation(), FirstPersonCameraComponent->GetComponentRotation(), SpawnInfo);
		break;
	case 2 :
		GetWorld()->SpawnActor<AHeavyPistol>(GunMesh->GetComponentLocation(), FirstPersonCameraComponent->GetComponentRotation(), SpawnInfo);
		break;
	case 3:
		GetWorld()->SpawnActor<AShotgun>(GunMesh->GetComponentLocation(), FirstPersonCameraComponent->GetComponentRotation(), SpawnInfo);
		break;
	case 4:
		GetWorld()->SpawnActor<AShotgun>(GunMesh->GetComponentLocation(), FirstPersonCameraComponent->GetComponentRotation(), SpawnInfo);
		break;
	default:
		break;
	}

}
*/

/*
void Aplayer_cpp::StopShooting()
{
	IsShooting = false;
	ShootingDelay = 0;
	//BeamParticle->SetHiddenInGame(true);
}
*/

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
				//GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("WALL RIGHT")));
				wallOnRight = true;
			}
		}
		else
		{
			//GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Purple, FString::Printf(TEXT("WALL NOT RIGHT")));
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
				//GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("WALL LEFT")));
				wallOnLeft = true;
			}
		}
		else
		{
			//GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Purple, FString::Printf(TEXT("WALL NOT LEFT")));
			wallOnLeft = false;
		}
	}
	//DOWNWARDS LINETRACE, CHECKS TO SEE IF PLAYER NIS ON THE FLOOR
	{
		//calculates the linetrace
		FHitResult OutHit;
		FVector Start = GetCapsuleComponent()->GetComponentLocation();
		FVector UpVector = GetCapsuleComponent()->GetUpVector();
		FVector End = FVector(Start.X, Start.Y, Start.Z - 250);
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(this);
		//does the linetrace
		if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams))
		{
			if (OutHit.bBlockingHit)
			{
				//GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("ON FLOOR")));
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
				//GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Green, FString::Printf(TEXT("CAN VAULT")));
				canVault = true;
			}
		}
		else
		{
			canVault = false;
			//GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Green, FString::Printf(TEXT("CAN'T VAULT")));
		}
	}
	{
		//ACTIVATES WALLRUNS AND CHECKS TO SEE IF PLAYER CAN WALLRUN
		if (wallOnRight == false && wallOnLeft == false)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("CANT WALL RUN")));
			canWallRun = false;
			isWallRunning = false;
			endWallRun();
		}
		else
		{
			//GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("CAN WALL RUN")));
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
	//if (this->GetActorLocation().Z <= -1000)
	//{
	//	this->SetActorLocation(FVector(0, 0, 1000));
	//}
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
