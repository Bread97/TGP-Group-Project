// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FingerGunz/PlayerStats.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerStats() {}
// Cross Module References
	FINGERGUNZ_API UScriptStruct* Z_Construct_UScriptStruct_FPlayerStats();
	UPackage* Z_Construct_UPackage__Script_FingerGunz();
// End Cross Module References
class UScriptStruct* FPlayerStats::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern FINGERGUNZ_API uint32 Get_Z_Construct_UScriptStruct_FPlayerStats_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FPlayerStats, Z_Construct_UPackage__Script_FingerGunz(), TEXT("PlayerStats"), sizeof(FPlayerStats), Get_Z_Construct_UScriptStruct_FPlayerStats_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FPlayerStats(FPlayerStats::StaticStruct, TEXT("/Script/FingerGunz"), TEXT("PlayerStats"), false, nullptr, nullptr);
static struct FScriptStruct_FingerGunz_StaticRegisterNativesFPlayerStats
{
	FScriptStruct_FingerGunz_StaticRegisterNativesFPlayerStats()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("PlayerStats")),new UScriptStruct::TCppStructOps<FPlayerStats>);
	}
} ScriptStruct_FingerGunz_StaticRegisterNativesFPlayerStats;
	struct Z_Construct_UScriptStruct_FPlayerStats_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_totalDeaths_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_totalDeaths;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_totalKills_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_totalKills;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPlayerStats_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "PlayerStats.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPlayerStats_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPlayerStats>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPlayerStats_Statics::NewProp_totalDeaths_MetaData[] = {
		{ "Category", "PlayerStats" },
		{ "ModuleRelativePath", "PlayerStats.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FPlayerStats_Statics::NewProp_totalDeaths = { UE4CodeGen_Private::EPropertyClass::Int, "totalDeaths", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FPlayerStats, totalDeaths), METADATA_PARAMS(Z_Construct_UScriptStruct_FPlayerStats_Statics::NewProp_totalDeaths_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerStats_Statics::NewProp_totalDeaths_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPlayerStats_Statics::NewProp_totalKills_MetaData[] = {
		{ "Category", "PlayerStats" },
		{ "ModuleRelativePath", "PlayerStats.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FPlayerStats_Statics::NewProp_totalKills = { UE4CodeGen_Private::EPropertyClass::Int, "totalKills", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FPlayerStats, totalKills), METADATA_PARAMS(Z_Construct_UScriptStruct_FPlayerStats_Statics::NewProp_totalKills_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerStats_Statics::NewProp_totalKills_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPlayerStats_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerStats_Statics::NewProp_totalDeaths,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerStats_Statics::NewProp_totalKills,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPlayerStats_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FingerGunz,
		nullptr,
		&NewStructOps,
		"PlayerStats",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		sizeof(FPlayerStats),
		alignof(FPlayerStats),
		Z_Construct_UScriptStruct_FPlayerStats_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerStats_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FPlayerStats_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerStats_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPlayerStats()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FPlayerStats_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_FingerGunz();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("PlayerStats"), sizeof(FPlayerStats), Get_Z_Construct_UScriptStruct_FPlayerStats_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FPlayerStats_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FPlayerStats_CRC() { return 1267046737U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
