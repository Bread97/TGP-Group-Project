// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FINGERGUNS_PlayerClass_generated_h
#error "PlayerClass.generated.h already included, missing '#pragma once' in PlayerClass.h"
#endif
#define FINGERGUNS_PlayerClass_generated_h

#define FingerGuns_Source_FingerGuns_PlayerClass_h_12_RPC_WRAPPERS
#define FingerGuns_Source_FingerGuns_PlayerClass_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define FingerGuns_Source_FingerGuns_PlayerClass_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayerClass(); \
	friend struct Z_Construct_UClass_APlayerClass_Statics; \
public: \
	DECLARE_CLASS(APlayerClass, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FingerGuns"), NO_API) \
	DECLARE_SERIALIZER(APlayerClass)


#define FingerGuns_Source_FingerGuns_PlayerClass_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAPlayerClass(); \
	friend struct Z_Construct_UClass_APlayerClass_Statics; \
public: \
	DECLARE_CLASS(APlayerClass, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FingerGuns"), NO_API) \
	DECLARE_SERIALIZER(APlayerClass)


#define FingerGuns_Source_FingerGuns_PlayerClass_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlayerClass(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlayerClass) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerClass); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerClass); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerClass(APlayerClass&&); \
	NO_API APlayerClass(const APlayerClass&); \
public:


#define FingerGuns_Source_FingerGuns_PlayerClass_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerClass(APlayerClass&&); \
	NO_API APlayerClass(const APlayerClass&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerClass); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerClass); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlayerClass)


#define FingerGuns_Source_FingerGuns_PlayerClass_h_12_PRIVATE_PROPERTY_OFFSET
#define FingerGuns_Source_FingerGuns_PlayerClass_h_9_PROLOG
#define FingerGuns_Source_FingerGuns_PlayerClass_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FingerGuns_Source_FingerGuns_PlayerClass_h_12_PRIVATE_PROPERTY_OFFSET \
	FingerGuns_Source_FingerGuns_PlayerClass_h_12_RPC_WRAPPERS \
	FingerGuns_Source_FingerGuns_PlayerClass_h_12_INCLASS \
	FingerGuns_Source_FingerGuns_PlayerClass_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FingerGuns_Source_FingerGuns_PlayerClass_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FingerGuns_Source_FingerGuns_PlayerClass_h_12_PRIVATE_PROPERTY_OFFSET \
	FingerGuns_Source_FingerGuns_PlayerClass_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FingerGuns_Source_FingerGuns_PlayerClass_h_12_INCLASS_NO_PURE_DECLS \
	FingerGuns_Source_FingerGuns_PlayerClass_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FingerGuns_Source_FingerGuns_PlayerClass_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
