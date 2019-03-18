// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FingerGunz/Heavy_Pistol.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHeavy_Pistol() {}
// Cross Module References
	FINGERGUNZ_API UClass* Z_Construct_UClass_AHeavy_Pistol_NoRegister();
	FINGERGUNZ_API UClass* Z_Construct_UClass_AHeavy_Pistol();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_FingerGunz();
// End Cross Module References
	void AHeavy_Pistol::StaticRegisterNativesAHeavy_Pistol()
	{
	}
	UClass* Z_Construct_UClass_AHeavy_Pistol_NoRegister()
	{
		return AHeavy_Pistol::StaticClass();
	}
	struct Z_Construct_UClass_AHeavy_Pistol_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHeavy_Pistol_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_FingerGunz,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeavy_Pistol_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Heavy_Pistol.h" },
		{ "ModuleRelativePath", "Heavy_Pistol.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHeavy_Pistol_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHeavy_Pistol>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHeavy_Pistol_Statics::ClassParams = {
		&AHeavy_Pistol::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AHeavy_Pistol_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AHeavy_Pistol_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHeavy_Pistol()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHeavy_Pistol_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHeavy_Pistol, 3116081243);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHeavy_Pistol(Z_Construct_UClass_AHeavy_Pistol, &AHeavy_Pistol::StaticClass, TEXT("/Script/FingerGunz"), TEXT("AHeavy_Pistol"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHeavy_Pistol);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
