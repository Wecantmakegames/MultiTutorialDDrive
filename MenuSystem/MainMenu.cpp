 // Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"

#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"

bool UMainMenu::Initialize()
{
	//if(!Super::Initialize()) return false;
	bool Success = Super::Initialize();
	if (!Success) return false;

	// TODO: setup
	if (!ensure(HostButton != nullptr)) return false;
	HostButton->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	if (!ensure(JoinButton != nullptr)) return false;
	JoinButton->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);

	if (!ensure(CancelButton != nullptr)) return false;
	CancelButton->OnClicked.AddDynamic(this, &UMainMenu::CancelOpenJoinMenu);

	if (!ensure(JoinConfirmButton != nullptr)) return false;
	JoinConfirmButton->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);

	if (!ensure(ExitGameButton != nullptr)) return false;
	ExitGameButton->OnClicked.AddDynamic(this, &UMainMenu::ExitGame);

	return true;
}

void UMainMenu::HostServer()
{
	UE_LOG(LogTemp, Warning, TEXT("I'm gonna host a server"));
	if (MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}
}

void UMainMenu::JoinServer()
{
	if (!ensure(IPAddressField != nullptr))
	{
		UE_LOG(LogTemp, Warning, TEXT("You must enter an IP Address"));
		return;
	}


	if (MenuInterface != nullptr)
	{
		MenuInterface->Join(IPAddressField->GetText().ToString());
	}
}

void UMainMenu::OpenJoinMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(JoinMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(JoinMenu);
}

void UMainMenu::CancelOpenJoinMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(MainMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(MainMenu);
}

void UMainMenu::ExitGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Exiting Game"));
	if (MenuInterface != nullptr)
	{
		MenuInterface->Exit();
	}
}
