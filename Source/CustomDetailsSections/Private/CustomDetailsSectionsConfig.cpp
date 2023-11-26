// Copyright 2023 Elemental Code (Milton Candelero). All Rights Reserved.

#include "CustomDetailsSectionsConfig.h"

inline UCustomDetailsSectionsConfig::UCustomDetailsSectionsConfig()
{
	CategoryName = TEXT("Plugins");
}

inline void UCustomDetailsSectionsConfig::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
{
	Super::PostEditChangeChainProperty(PropertyChangedEvent);

	// I am not checking the property name, I have only one property :|
		
	// Make sure no category has a | character. If they do, take the first segment
	for (FCustomDetailsSection& CustomDetailsSections : AllSections)
	{
		for (FName& Category : CustomDetailsSections.Categories)
		{
			if (Category.ToString().Contains(TEXT("|")))
			{
				Category = FName(*Category.ToString().Left(Category.ToString().Find(TEXT("|"))));
			}
		}
	}
}
