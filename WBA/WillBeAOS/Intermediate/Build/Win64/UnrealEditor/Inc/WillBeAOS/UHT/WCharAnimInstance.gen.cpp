// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WillBeAOS/Character/WCharAnimInstance.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWCharAnimInstance() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_WillBeAOS();
WILLBEAOS_API UClass* Z_Construct_UClass_AWCharacterBase_NoRegister();
WILLBEAOS_API UClass* Z_Construct_UClass_UWCharAnimInstance();
WILLBEAOS_API UClass* Z_Construct_UClass_UWCharAnimInstance_NoRegister();
// End Cross Module References

// Begin Class UWCharAnimInstance
void UWCharAnimInstance::StaticRegisterNativesUWCharAnimInstance()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UWCharAnimInstance);
UClass* Z_Construct_UClass_UWCharAnimInstance_NoRegister()
{
	return UWCharAnimInstance::StaticClass();
}
struct Z_Construct_UClass_UWCharAnimInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "Character/WCharAnimInstance.h" },
		{ "ModuleRelativePath", "Character/WCharAnimInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WCharBase_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Character/WCharAnimInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WCharMovementComponent_MetaData[] = {
		{ "Category", "Movement" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Character/WCharAnimInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WCharVelocity_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Character/WCharAnimInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WCharSpeed_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Character/WCharAnimInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WShouldMove_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Character/WCharAnimInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WCharInAir_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Character/WCharAnimInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FullBody_MetaData[] = {
		{ "Category", "WCharAnimInstance" },
		{ "ModuleRelativePath", "Character/WCharAnimInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WCharBase;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WCharMovementComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WCharVelocity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WCharSpeed;
	static void NewProp_WShouldMove_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_WShouldMove;
	static void NewProp_WCharInAir_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_WCharInAir;
	static void NewProp_FullBody_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_FullBody;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWCharAnimInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_WCharBase = { "WCharBase", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWCharAnimInstance, WCharBase), Z_Construct_UClass_AWCharacterBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WCharBase_MetaData), NewProp_WCharBase_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_WCharMovementComponent = { "WCharMovementComponent", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWCharAnimInstance, WCharMovementComponent), Z_Construct_UClass_UCharacterMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WCharMovementComponent_MetaData), NewProp_WCharMovementComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_WCharVelocity = { "WCharVelocity", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWCharAnimInstance, WCharVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WCharVelocity_MetaData), NewProp_WCharVelocity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_WCharSpeed = { "WCharSpeed", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWCharAnimInstance, WCharSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WCharSpeed_MetaData), NewProp_WCharSpeed_MetaData) };
void Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_WShouldMove_SetBit(void* Obj)
{
	((UWCharAnimInstance*)Obj)->WShouldMove = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_WShouldMove = { "WShouldMove", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UWCharAnimInstance), &Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_WShouldMove_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WShouldMove_MetaData), NewProp_WShouldMove_MetaData) };
void Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_WCharInAir_SetBit(void* Obj)
{
	((UWCharAnimInstance*)Obj)->WCharInAir = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_WCharInAir = { "WCharInAir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UWCharAnimInstance), &Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_WCharInAir_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WCharInAir_MetaData), NewProp_WCharInAir_MetaData) };
void Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_FullBody_SetBit(void* Obj)
{
	((UWCharAnimInstance*)Obj)->FullBody = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_FullBody = { "FullBody", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UWCharAnimInstance), &Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_FullBody_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FullBody_MetaData), NewProp_FullBody_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UWCharAnimInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_WCharBase,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_WCharMovementComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_WCharVelocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_WCharSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_WShouldMove,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_WCharInAir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWCharAnimInstance_Statics::NewProp_FullBody,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWCharAnimInstance_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UWCharAnimInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAnimInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_WillBeAOS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWCharAnimInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UWCharAnimInstance_Statics::ClassParams = {
	&UWCharAnimInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UWCharAnimInstance_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UWCharAnimInstance_Statics::PropPointers),
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UWCharAnimInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UWCharAnimInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UWCharAnimInstance()
{
	if (!Z_Registration_Info_UClass_UWCharAnimInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWCharAnimInstance.OuterSingleton, Z_Construct_UClass_UWCharAnimInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UWCharAnimInstance.OuterSingleton;
}
template<> WILLBEAOS_API UClass* StaticClass<UWCharAnimInstance>()
{
	return UWCharAnimInstance::StaticClass();
}
UWCharAnimInstance::UWCharAnimInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UWCharAnimInstance);
UWCharAnimInstance::~UWCharAnimInstance() {}
// End Class UWCharAnimInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_WillBeAOS_Source_WillBeAOS_Character_WCharAnimInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UWCharAnimInstance, UWCharAnimInstance::StaticClass, TEXT("UWCharAnimInstance"), &Z_Registration_Info_UClass_UWCharAnimInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWCharAnimInstance), 1837665473U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_WillBeAOS_Source_WillBeAOS_Character_WCharAnimInstance_h_2534279327(TEXT("/Script/WillBeAOS"),
	Z_CompiledInDeferFile_FID_WillBeAOS_Source_WillBeAOS_Character_WCharAnimInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_WillBeAOS_Source_WillBeAOS_Character_WCharAnimInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
