// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FingerGunz/HeavyPistol.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHeavyPistol() {}
// Cross Module References
	FINGERGUNZ_API UClass* Z_Construct_UClass_AHeavyPistol_NoRegister();
	FINGERGUNZ_API UClass* Z_Construct_UClass_AHeavyPistol();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_FingerGunz();
// End Cross Module References
	void AHeavyPistol::StaticRegisterNativesAHeavyPistol()
	{
	}
	UClass* Z_Construct_UClass_AHeavyPistol_NoRegister()
	{
		return AHeavyPistol::StaticClass();
	}
	struct Z_Construct_UClass_AHeavyPistol_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHeavyPistol_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_FingerGunz,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeavyPistol_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "HeavyPistol.h" },
		{ "ModuleRelativePath", "HeavyPistol.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHeavyPistol_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHeavyPistol>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHeavyPistol_Statics::ClassParams = {
		&AHeavyPistol::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AHeavyPistol_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AHeavyPistol_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHeavyPistol()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHeavyPistol_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHeavyPistol, 688702412);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHeavyPistol(Z_Construct_UClass_AHeavyPistol, &AHeavyPistol::StaticClass, TEXT("/Script/FingerGunz"), TEXT("AHeavyPistol"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHeavyPistol);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
