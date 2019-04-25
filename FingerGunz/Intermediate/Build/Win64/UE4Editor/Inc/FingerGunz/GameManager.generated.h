// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FINGERGUNZ_GameManager_generated_h
#error "GameManager.generated.h already included, missing '#pragma once' in GameManager.h"
#endif
#define FINGERGUNZ_GameManager_generated_h

#define FingerGunz_Source_FingerGunz_GameManager_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAddDeath) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_playerID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddDeath(Z_Param_playerID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddKill) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_playerID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddKill(Z_Param_playerID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRegisterPlayer) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->RegisterPlayer(); \
		P_NATIVE_END; \
	}


#define FingerGunz_Source_FingerGunz_GameManager_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAddDeath) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_playerID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddDeath(Z_Param_playerID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddKill) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_playerID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddKill(Z_Param_playerID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRegisterPlayer) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->RegisterPlayer(); \
		P_NATIVE_END; \
	}


#define FingerGunz_Source_FingerGunz_GameManager_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGameManager(); \
	friend struct Z_Construct_UClass_AGameManager_Statics; \
public: \
	DECLARE_CLASS(AGameManager, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FingerGunz"), NO_API) \
	DECLARE_SERIALIZER(AGameManager)


#define FingerGunz_Source_FingerGunz_GameManager_h_20_INCLASS \
private: \
	static void StaticRegisterNativesAGameManager(); \
	friend struct Z_Construct_UClass_AGameManager_Statics; \
public: \
	DECLARE_CLASS(AGameManager, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FingerGunz"), NO_API) \
	DECLARE_SERIALIZER(AGameManager)


#define FingerGunz_Source_FingerGunz_GameManager_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGameManager(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGameManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameManager(AGameManager&&); \
	NO_API AGameManager(const AGameManager&); \
public:


#define FingerGunz_Source_FingerGunz_GameManager_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameManager(AGameManager&&); \
	NO_API AGameManager(const AGameManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGameManager)


#define FingerGunz_Source_FingerGunz_GameManager_h_20_PRIVATE_PROPERTY_OFFSET
#define FingerGunz_Source_FingerGunz_GameManager_h_13_PROLOG
#define FingerGunz_Source_FingerGunz_GameManager_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FingerGunz_Source_FingerGunz_GameManager_h_20_PRIVATE_PROPERTY_OFFSET \
	FingerGunz_Source_FingerGunz_GameManager_h_20_RPC_WRAPPERS \
	FingerGunz_Source_FingerGunz_GameManager_h_20_INCLASS \
	FingerGunz_Source_FingerGunz_GameManager_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FingerGunz_Source_FingerGunz_GameManager_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FingerGunz_Source_FingerGunz_GameManager_h_20_PRIVATE_PROPERTY_OFFSET \
	FingerGunz_Source_FingerGunz_GameManager_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FingerGunz_Source_FingerGunz_GameManager_h_20_INCLASS_NO_PURE_DECLS \
	FingerGunz_Source_FingerGunz_GameManager_h_20_ENHANCED_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FingerGunz_Source_FingerGunz_GameManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
