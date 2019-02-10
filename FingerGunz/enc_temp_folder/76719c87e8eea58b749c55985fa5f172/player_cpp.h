// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "player_cpp.generated.h"

UCLASS()
class FINGERGUNZ_API Aplayer_cpp : public ACharacter
{

	UCharacterMovementComponent* CharacterMovement = GetCharacterMovement();

public:
	// Sets default values for this character's properties
	Aplayer_cpp();
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FirstPersonCameraComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void moveForward(float val);
	void moveRight(float val);
	void turnAtRate(float Rate);
	void lookUpAtRate(float Rate);
	void tryWallRun();
	void tryStopWallRun();
	bool isWallRunning;
	bool isOnWall;
	float wallJumpAmount;
	bool canWallRun;
	bool wallOnRight;
	bool wallOnLeft;
	bool onFloor;
	void doWallRun(bool left, bool right);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;
	
	
};
