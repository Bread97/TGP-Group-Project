// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ParticleDefinitions.h"
#include "player_cpp.generated.h"

UCLASS()
class FINGERGUNZ_API Aplayer_cpp : public ACharacter
{

	UCharacterMovementComponent* CharacterMovement = GetCharacterMovement();

public:
	// Sets default values for this character's properties
	Aplayer_cpp(const FObjectInitializer& PCIP);
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FirstPersonCameraComponent;
	//BROKEN AT THE MOMENT
	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Effects)
	//	UParticleSystem* BeamEffect;
	//BROKEN AT THE MOMENT


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Setup Movement Variables
	void moveForward(float val);
	void moveRight(float val);
	void turnAtRate(float Rate);
	void lookUpAtRate(float Rate);

	//Setup Parkour Bariables
	void tryWallRun();
	void tryStopWallRun();
	bool isWallRunning;
	bool isOnWall;
	float wallJumpAmount;
	bool canWallRun;
	bool wallOnRight;
	bool wallOnLeft;
	bool onFloor;
	void doWallRun();
	void endWallRun();
	void doWallJump();
	bool canWallJump;
	bool canVault;
	bool isVaulting;
	void tryVault();
	void doVault();
	void endVault();
	float vaultJumpAmount;

	//Setup Weapon Variables
	void shoot();
	void StopShooting();
	bool IsShooting;
	int ShootingDelay;
	void beplayer1();
	FString ObjectHit;
	float PistolDamageAmount;
	void StartZoom();
	void EndZoom();
	void ChangeRight();

	//Setup Player Properties
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Int, meta = (AllowPrivateAccess = "true"))
		int Health;
	int Armor;
	int CurrentWeapon = 0;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;
	
	//UStaticMeshComponent* StaticMesh;
	UStaticMeshComponent* PlayerStaticMesh;
	UStaticMeshComponent* GunStaticMesh;
	UParticleSystemComponent* BeamParticle;
	TSubclassOf<class AItem> BeamActor_BP;

	void TakeDamage(float Damage);

};
