// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FingerGunz/FingerGunzGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFingerGunzGameModeBase() {}
// Cross Module References
	FINGERGUNZ_API UClass* Z_Construct_UClass_AFingerGunzGameModeBase_NoRegister();
	FINGERGUNZ_API UClass* Z_Construct_UClass_AFingerGunzGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_FingerGunz();
// End Cross Module References
	void AFingerGunzGameModeBase::StaticRegisterNativesAFingerGunzGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AFingerGunzGameModeBase_NoRegister()
	{
		return AFingerGunzGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AFingerGunzGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFingerGunzGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_FingerGunz,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFingerGunzGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "FingerGunzGameModeBase.h" },
		{ "ModuleRelativePath", "FingerGunzGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFingerGunzGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFingerGunzGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFingerGunzGameModeBase_Statics::ClassParams = {
		&AFingerGunzGameModeBase::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A8u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AFingerGunzGameModeBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AFingerGunzGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFingerGunzGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFingerGunzGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFingerGunzGameModeBase, 2082512977);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFingerGunzGameModeBase(Z_Construct_UClass_AFingerGunzGameModeBase, &AFingerGunzGameModeBase::StaticClass, TEXT("/Script/FingerGunz"), TEXT("AFingerGunzGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFingerGunzGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
