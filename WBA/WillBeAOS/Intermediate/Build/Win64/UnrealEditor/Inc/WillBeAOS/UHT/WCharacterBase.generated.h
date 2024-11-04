// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Character/WCharacterBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef WILLBEAOS_WCharacterBase_generated_h
#error "WCharacterBase.generated.h already included, missing '#pragma once' in WCharacterBase.h"
#endif
#define WILLBEAOS_WCharacterBase_generated_h

#define FID_WillBeAOS_Source_WillBeAOS_Character_WCharacterBase_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWCharacterBase(); \
	friend struct Z_Construct_UClass_AWCharacterBase_Statics; \
public: \
	DECLARE_CLASS(AWCharacterBase, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/WillBeAOS"), NO_API) \
	DECLARE_SERIALIZER(AWCharacterBase)


#define FID_WillBeAOS_Source_WillBeAOS_Character_WCharacterBase_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AWCharacterBase(AWCharacterBase&&); \
	AWCharacterBase(const AWCharacterBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWCharacterBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWCharacterBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWCharacterBase) \
	NO_API virtual ~AWCharacterBase();


#define FID_WillBeAOS_Source_WillBeAOS_Character_WCharacterBase_h_10_PROLOG
#define FID_WillBeAOS_Source_WillBeAOS_Character_WCharacterBase_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_WillBeAOS_Source_WillBeAOS_Character_WCharacterBase_h_14_INCLASS_NO_PURE_DECLS \
	FID_WillBeAOS_Source_WillBeAOS_Character_WCharacterBase_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> WILLBEAOS_API UClass* StaticClass<class AWCharacterBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_WillBeAOS_Source_WillBeAOS_Character_WCharacterBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
