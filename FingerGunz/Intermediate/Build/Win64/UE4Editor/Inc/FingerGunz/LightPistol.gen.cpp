// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FingerGunz/LightPistol.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLightPistol() {}
// Cross Module References
	FINGERGUNZ_API UClass* Z_Construct_UClass_ALightPistol_NoRegister();
	FINGERGUNZ_API UClass* Z_Construct_UClass_ALightPistol();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_FingerGunz();
// End Cross Module References
	void ALightPistol::StaticRegisterNativesALightPistol()
	{
	}
	UClass* Z_Construct_UClass_ALightPistol_NoRegister()
	{
		return ALightPistol::StaticClass();
	}
	struct Z_Construct_UClass_ALightPistol_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALightPistol_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_FingerGunz,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALightPistol_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "LightPistol.h" },
		{ "ModuleRelativePath", "LightPistol.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALightPistol_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALightPistol>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALightPistol_Statics::ClassParams = {
		&ALightPistol::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ALightPistol_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ALightPistol_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALightPistol()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ALightPistol_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALightPistol, 1500833337);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALightPistol(Z_Construct_UClass_ALightPistol, &ALightPistol::StaticClass, TEXT("/Script/FingerGunz"), TEXT("ALightPistol"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALightPistol);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
