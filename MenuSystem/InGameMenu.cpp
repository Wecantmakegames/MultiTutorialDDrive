// Fill out your copyright notice in the Description page of Project Settings.

#include "InGameMenu.h"

#include "Components/Button.h"

bool UInGameMenu::Initialize()
{
	//if(!Super::Initialize()) return false;
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(CancelButton != nullptr)) return false;
	CancelButton->OnClicked.AddDynamic(this, &UInGameMenu::ExitMenu);

	if (!ensure(QuitButton != nullptr)) return false;
	QuitButton->OnClicked.AddDynamic(this, &UInGameMenu::QuitToMainMenu);

	return true;
}

void UInGameMenu::ExitMenu()
{
	this->Teardown();
}

void UInGameMenu::QuitToMainMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("Quitting to the Main Menu"));

	if (MenuInterface != nullptr)
	{
		this->ExitMenu();
		MenuInterface->Quit();
	}
}

// TODO quit to main menu