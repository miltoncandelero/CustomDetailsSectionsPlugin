// Copyright 2023 Elemental Code (Milton Candelero). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "CustomDetailsSectionsConfig.generated.h"

USTRUCT()
struct FCustomDetailsSection
{
	GENERATED_BODY()

	// On which class will this section be visible? Children of the class also inherit the section
	UPROPERTY(EditAnywhere, Category="Custom Details Sections", meta=(DisplayName="Class", AllowAbstract = "true"))
	FSoftClassPath Class;

	// Unique identifier for this section. Can be the same as another one to append to 
	UPROPERTY(EditAnywhere, Category="Custom Details Sections", meta=(DisplayName="Section Id"))
	FName SectionId;

	// This is what will show up in the UI. If appending to an existing section, this can override the existing name
	UPROPERTY(EditAnywhere, Category="Custom Details Sections", meta=(DisplayName="Display Name"))
	FText DisplayName;

	// You need to add the category to your variables for them to show up in the section
	UPROPERTY(EditAnywhere, Category="Custom Details Sections", meta=(DisplayName="Categories to add to the section"))
	TArray<FName> Categories;
};

/**
 * 
 */
UCLASS(Config=EditorPerProjectUserSettings, DefaultConfig, meta=(DisplayName="Custom Details Sections"))
class CUSTOMDETAILSSECTIONS_API UCustomDetailsSectionsConfig : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UCustomDetailsSectionsConfig();

	virtual void PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent) override;

	// List of sections to add to the property editor
	UPROPERTY(Config, EditAnywhere, Category="Custom Details Sections", meta=(ConfigRestartRequired=true, TitleProperty="{DisplayName} ({SectionId}) on {Class}"))
	TArray<FCustomDetailsSection> AllSections;
};