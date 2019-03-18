// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FingerGunz/ShotGun.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShotGun() {}
// Cross Module References
	FINGERGUNZ_API UClass* Z_Construct_UClass_AShotgun_NoRegister();
	FINGERGUNZ_API UClass* Z_Construct_UClass_AShotgun();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_FingerGunz();
// End Cross Module References
	void AShotgun::StaticRegisterNativesAShotgun()
	{
	}
	UClass* Z_Construct_UClass_AShotgun_NoRegister()
	{
		return AShotgun::StaticClass();
	}
	struct Z_Construct_UClass_AShotgun_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AShotgun_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_FingerGunz,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShotgun_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ShotGun.h" },
		{ "ModuleRelativePath", "ShotGun.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AShotgun_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShotgun>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AShotgun_Statics::ClassParams = {
		&AShotgun::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AShotgun_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AShotgun_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AShotgun()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AShotgun_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AShotgun, 251247261);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShotgun(Z_Construct_UClass_AShotgun, &AShotgun::StaticClass, TEXT("/Script/FingerGunz"), TEXT("AShotgun"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AShotgun);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
