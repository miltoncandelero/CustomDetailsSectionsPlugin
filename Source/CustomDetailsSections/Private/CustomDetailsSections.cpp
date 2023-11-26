// Copyright 2023 Elemental Code (Milton Candelero). All Rights Reserved.

#include "CustomDetailsSections.h"

#include "CustomDetailsSectionsConfig.h"

static const FName PropertyEditor("PropertyEditor");

#define LOCTEXT_NAMESPACE "FCustomDetailsSectionsModule"

void FCustomDetailsSectionsModule::StartupModule()
{
	const UCustomDetailsSectionsConfig* Config = GetDefault<UCustomDetailsSectionsConfig>();
	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>(PropertyEditor);

	for (const FCustomDetailsSection& CustomDetailsSections : Config->AllSections)
	{
		if (CustomDetailsSections.Class.IsValid())
		{
			const TSharedRef<FPropertySection> Section = PropertyModule.FindOrCreateSection(CustomDetailsSections.Class.GetAssetFName(), CustomDetailsSections.SectionId, CustomDetailsSections.DisplayName);
			
			for (const FName& Category : CustomDetailsSections.Categories)
			{
				// Let's not crash, shall we?
				if (Category.ToString().Contains(TEXT("|")))
				{
					Section->AddCategory(FName(*Category.ToString().Left(Category.ToString().Find(TEXT("|")))));
				}
				else
				{
					Section->AddCategory(Category);
				}
			}
		}
	}
}

void FCustomDetailsSectionsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FCustomDetailsSectionsModule, CustomDetailsSections)
