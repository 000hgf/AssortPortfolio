// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WillBeAOS/Character/WCharacterBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWCharacterBase() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
UPackage* Z_Construct_UPackage__Script_WillBeAOS();
WILLBEAOS_API UClass* Z_Construct_UClass_AWCharacterBase();
WILLBEAOS_API UClass* Z_Construct_UClass_AWCharacterBase_NoRegister();
// End Cross Module References

// Begin Class AWCharacterBase
void AWCharacterBase::StaticRegisterNativesAWCharacterBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWCharacterBase);
UClass* Z_Construct_UClass_AWCharacterBase_NoRegister()
{
	return AWCharacterBase::StaticClass();
}
struct Z_Construct_UClass_AWCharacterBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/WCharacterBase.h" },
		{ "ModuleRelativePath", "Character/WCharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Character/WCharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Character/WCharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IMC_Asset_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/WCharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_Look_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/WCharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_Move_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/WCharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_Jump_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/WCharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_Behavior_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/WCharacterBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IMC_Asset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Look;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Move;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Jump;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Behavior;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWCharacterBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWCharacterBase_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWCharacterBase, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraBoom_MetaData), NewProp_CameraBoom_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWCharacterBase_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWCharacterBase, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FollowCamera_MetaData), NewProp_FollowCamera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWCharacterBase_Statics::NewProp_IMC_Asset = { "IMC_Asset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWCharacterBase, IMC_Asset), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IMC_Asset_MetaData), NewProp_IMC_Asset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWCharacterBase_Statics::NewProp_IA_Look = { "IA_Look", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWCharacterBase, IA_Look), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Look_MetaData), NewProp_IA_Look_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWCharacterBase_Statics::NewProp_IA_Move = { "IA_Move", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWCharacterBase, IA_Move), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Move_MetaData), NewProp_IA_Move_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWCharacterBase_Statics::NewProp_IA_Jump = { "IA_Jump", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWCharacterBase, IA_Jump), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Jump_MetaData), NewProp_IA_Jump_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWCharacterBase_Statics::NewProp_IA_Behavior = { "IA_Behavior", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWCharacterBase, IA_Behavior), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Behavior_MetaData), NewProp_IA_Behavior_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWCharacterBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWCharacterBase_Statics::NewProp_CameraBoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWCharacterBase_Statics::NewProp_FollowCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWCharacterBase_Statics::NewProp_IMC_Asset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWCharacterBase_Statics::NewProp_IA_Look,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWCharacterBase_Statics::NewProp_IA_Move,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWCharacterBase_Statics::NewProp_IA_Jump,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWCharacterBase_Statics::NewProp_IA_Behavior,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWCharacterBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AWCharacterBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_WillBeAOS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWCharacterBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AWCharacterBase_Statics::ClassParams = {
	&AWCharacterBase::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AWCharacterBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AWCharacterBase_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWCharacterBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AWCharacterBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AWCharacterBase()
{
	if (!Z_Registration_Info_UClass_AWCharacterBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWCharacterBase.OuterSingleton, Z_Construct_UClass_AWCharacterBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AWCharacterBase.OuterSingleton;
}
template<> WILLBEAOS_API UClass* StaticClass<AWCharacterBase>()
{
	return AWCharacterBase::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AWCharacterBase);
AWCharacterBase::~AWCharacterBase() {}
// End Class AWCharacterBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_WillBeAOS_Source_WillBeAOS_Character_WCharacterBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AWCharacterBase, AWCharacterBase::StaticClass, TEXT("AWCharacterBase"), &Z_Registration_Info_UClass_AWCharacterBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWCharacterBase), 2853299154U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_WillBeAOS_Source_WillBeAOS_Character_WCharacterBase_h_2561053568(TEXT("/Script/WillBeAOS"),
	Z_CompiledInDeferFile_FID_WillBeAOS_Source_WillBeAOS_Character_WCharacterBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_WillBeAOS_Source_WillBeAOS_Character_WCharacterBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
