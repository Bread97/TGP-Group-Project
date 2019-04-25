// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FingerGunz/GameManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameManager() {}
// Cross Module References
	FINGERGUNZ_API UClass* Z_Construct_UClass_AGameManager_NoRegister();
	FINGERGUNZ_API UClass* Z_Construct_UClass_AGameManager();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_FingerGunz();
	FINGERGUNZ_API UFunction* Z_Construct_UFunction_AGameManager_AddDeath();
	FINGERGUNZ_API UFunction* Z_Construct_UFunction_AGameManager_AddKill();
	FINGERGUNZ_API UFunction* Z_Construct_UFunction_AGameManager_RegisterPlayer();
	FINGERGUNZ_API UScriptStruct* Z_Construct_UScriptStruct_FPlayerStats();
// End Cross Module References
	void AGameManager::StaticRegisterNativesAGameManager()
	{
		UClass* Class = AGameManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddDeath", &AGameManager::execAddDeath },
			{ "AddKill", &AGameManager::execAddKill },
			{ "RegisterPlayer", &AGameManager::execRegisterPlayer },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AGameManager_AddDeath_Statics
	{
		struct GameManager_eventAddDeath_Parms
		{
			int32 playerID;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_playerID;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AGameManager_AddDeath_Statics::NewProp_playerID = { UE4CodeGen_Private::EPropertyClass::Int, "playerID", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(GameManager_eventAddDeath_Parms, playerID), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGameManager_AddDeath_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGameManager_AddDeath_Statics::NewProp_playerID,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGameManager_AddDeath_Statics::Function_MetaDataParams[] = {
		{ "Category", "Game Manager" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGameManager_AddDeath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGameManager, "AddDeath", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(GameManager_eventAddDeath_Parms), Z_Construct_UFunction_AGameManager_AddDeath_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AGameManager_AddDeath_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGameManager_AddDeath_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AGameManager_AddDeath_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGameManager_AddDeath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGameManager_AddDeath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AGameManager_AddKill_Statics
	{
		struct GameManager_eventAddKill_Parms
		{
			int32 playerID;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_playerID;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AGameManager_AddKill_Statics::NewProp_playerID = { UE4CodeGen_Private::EPropertyClass::Int, "playerID", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(GameManager_eventAddKill_Parms, playerID), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGameManager_AddKill_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGameManager_AddKill_Statics::NewProp_playerID,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGameManager_AddKill_Statics::Function_MetaDataParams[] = {
		{ "Category", "Game Manager" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGameManager_AddKill_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGameManager, "AddKill", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(GameManager_eventAddKill_Parms), Z_Construct_UFunction_AGameManager_AddKill_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AGameManager_AddKill_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGameManager_AddKill_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AGameManager_AddKill_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGameManager_AddKill()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGameManager_AddKill_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AGameManager_RegisterPlayer_Statics
	{
		struct GameManager_eventRegisterPlayer_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AGameManager_RegisterPlayer_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(GameManager_eventRegisterPlayer_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGameManager_RegisterPlayer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGameManager_RegisterPlayer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGameManager_RegisterPlayer_Statics::Function_MetaDataParams[] = {
		{ "Category", "Game Manager" },
		{ "ModuleRelativePath", "GameManager.h" },
		{ "ToolTip", "Returns a player ID for the originating character" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGameManager_RegisterPlayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGameManager, "RegisterPlayer", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(GameManager_eventRegisterPlayer_Parms), Z_Construct_UFunction_AGameManager_RegisterPlayer_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AGameManager_RegisterPlayer_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGameManager_RegisterPlayer_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AGameManager_RegisterPlayer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGameManager_RegisterPlayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGameManager_RegisterPlayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AGameManager_NoRegister()
	{
		return AGameManager::StaticClass();
	}
	struct Z_Construct_UClass_AGameManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_players_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_players;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_players_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGameManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_FingerGunz,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AGameManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AGameManager_AddDeath, "AddDeath" }, // 2224888380
		{ &Z_Construct_UFunction_AGameManager_AddKill, "AddKill" }, // 2047275326
		{ &Z_Construct_UFunction_AGameManager_RegisterPlayer, "RegisterPlayer" }, // 1826293218
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GameManager.h" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameManager_Statics::NewProp_players_MetaData[] = {
		{ "Category", "GameManager" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AGameManager_Statics::NewProp_players = { UE4CodeGen_Private::EPropertyClass::Array, "players", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000020015, 1, nullptr, STRUCT_OFFSET(AGameManager, players), METADATA_PARAMS(Z_Construct_UClass_AGameManager_Statics::NewProp_players_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameManager_Statics::NewProp_players_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGameManager_Statics::NewProp_players_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "players", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000020000, 1, nullptr, 0, Z_Construct_UScriptStruct_FPlayerStats, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGameManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameManager_Statics::NewProp_players,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameManager_Statics::NewProp_players_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGameManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGameManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGameManager_Statics::ClassParams = {
		&AGameManager::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AGameManager_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AGameManager_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AGameManager_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AGameManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGameManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGameManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGameManager, 3614894533);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGameManager(Z_Construct_UClass_AGameManager, &AGameManager::StaticClass, TEXT("/Script/FingerGunz"), TEXT("AGameManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGameManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
