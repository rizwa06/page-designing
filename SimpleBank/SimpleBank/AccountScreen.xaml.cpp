//
// AccountScreen.xaml.cpp
// Implementation of the AccountScreen class
//

#include "pch.h"
#include "AccountScreen.xaml.h"
#include <cstdlib>
#include <tuple>

using namespace SimpleBank;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

AccountScreen::AccountScreen()
{
	InitializeComponent();
}

void SimpleBank::AccountScreen::OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs ^ e)
{
	m_CurProf = (BankProfile^)e->Parameter;

	lab_UserName->Text = m_CurProf->GetName();

	UpdateAccountsView();

	::Windows::UI::Xaml::Controls::Page::OnNavigatedTo(e);
}

void SimpleBank::AccountScreen::bt_AddAccount_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	pbx_AddAccnt->IsOpen = true;
}

void SimpleBank::AccountScreen::bt_Logout_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->GoBack();
}

void SimpleBank::AccountScreen::bt_Close_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	pbx_AddAccnt->IsOpen = false;
}

void SimpleBank::AccountScreen::AddAccountButton(Platform::String^ Text)
{
	Button^ btn = ref new Button();
	btn->Content = Text;
	btn->Width = sp_AccountList->Width;

	btn->Click += ref new RoutedEventHandler(this, &SimpleBank::AccountScreen::AccountBtnClick);
	sp_AccountList->Children->Append(btn);
}

void SimpleBank::AccountScreen::UpdateCurrentAccount()
{
	lab_AccNumber->Text = Utilities::stringToPlatformString(std::to_string(m_CurAcc->GetAccNumber()));
	lab_Balance->Text = "Balance: " + Utilities::stringToPlatformString(std::to_string(m_CurAcc->GetBalance()));
	lab_OverdraftLimit->Text = "Overdraft Limit: " + Utilities::stringToPlatformString(std::to_string(m_CurAcc->GetOverdraftLimit()));

	//Clean SP
	sp_ActivityLogLeft->Children->Clear();
	sp_ActivityLogCen->Children->Clear();
	sp_ActivityLogRight->Children->Clear();

	//Add Headers
	TextBlock^ LeftHeader = ref new TextBlock();
	TextBlock^ CenterHeader = ref new TextBlock();
	TextBlock^ RightHeader = ref new TextBlock();
	LeftHeader->Text = "Activity Type:";
	CenterHeader->Text = "Other Account*:";
	RightHeader->Text = "Amount:";

	sp_ActivityLogLeft->Children->Append(LeftHeader);
	sp_ActivityLogCen->Children->Append(CenterHeader);
	sp_ActivityLogRight->Children->Append(RightHeader);
	//

	//Update Activity
	for (int i = 0; i < m_CurAcc->GetActivitySize(); i++)
	{
		Transaction^ Currentit = m_CurAcc->GetActivityAt(i);

		TextBlock^ tb_ActType = ref new TextBlock();
		TextBlock^ tb_OtherAcc = ref new TextBlock();
		TextBlock^ tb_Amount = ref new TextBlock();

		tb_ActType->Text = Currentit->GetActivityType();
		if (Currentit->IsPayment())
			tb_OtherAcc->Text = Utilities::stringToPlatformString(std::to_string(Currentit->GetOthAccNum()));
		
		tb_Amount->Text = "Amount: " + Currentit->GetAmount();

		sp_ActivityLogLeft->Children->Append(tb_ActType);
		sp_ActivityLogCen->Children->Append(tb_OtherAcc);
		sp_ActivityLogRight->Children->Append(tb_Amount);
	}
}

void SimpleBank::AccountScreen::UpdateAccountsView()
{
	//Clear
	sp_AccountList->Children->Clear();
	//Add Accounts to list
	for (int i = 0; i < m_CurProf->GetAccountSize(); i++)
	{
		Platform::String^ Text = Utilities::stringToPlatformString(
			std::to_string(m_CurProf->GetAccount(i)->GetAccNumber()) + " : "
		) + m_CurProf->GetAccount(i)->GetAccTypeStr();
		AddAccountButton(Text);
	}
}

void SimpleBank::AccountScreen::AccountBtnClick(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Button^ This = (Button^)sender;

	std::string ButtonText = Utilities::convert_plat_string((Platform::String^)This->Content);
	std::string Delimiter = " : ";
	std::string AccNumToken = ButtonText.substr(0, ButtonText.find(Delimiter));


	m_CurAcc = m_CurProf->FindAccount(std::stoi(AccNumToken));

	UpdateCurrentAccount();
}

void SimpleBank::AccountScreen::TransButtonClick(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e)
{
	Button^ This = (Button^)sender;

	std::string ButtonText = Utilities::convert_plat_string((Platform::String^)This->Content);
	std::string Delimiter = " : ";
	std::string AccNumToken = ButtonText.substr(0, ButtonText.find(Delimiter));

	m_CurAcc_trans = m_CurProf->FindAccount(std::stoi(AccNumToken));
}

void SimpleBank::AccountScreen::bt_Deposit_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	float Amount = ::atof(Utilities::convert_plat_string(tb_Deposit->Text).c_str());
	m_CurAcc->Deposit(Amount, false);
	UpdateCurrentAccount();
}

void SimpleBank::AccountScreen::bt_Withdraw_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	float Amount = ::atof(Utilities::convert_plat_string(tb_Withdraw->Text).c_str());
	m_CurAcc->Withdraw(Amount, false);
	UpdateCurrentAccount();
}

void SimpleBank::AccountScreen::bt_MakePayment_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	pbx_MakePayment->IsOpen = true;
}

void SimpleBank::AccountScreen::bt_Transfer_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	pbx_Transfer->IsOpen = true;

	//GetAccounts
	for (int i = 0; i < m_CurProf->GetAccountSize(); i++)
	{
		if (m_CurProf->GetAccount(i) != m_CurAcc)
		{
			Button^ btn = ref new Button();

			Platform::String^ Text = Utilities::stringToPlatformString(
				std::to_string(m_CurProf->GetAccount(i)->GetAccNumber()) + " : "
			) + m_CurProf->GetAccount(i)->GetAccTypeStr();

			btn->Content = Text;
			btn->Width = grd_Transfer->Width;

			btn->Click += ref new RoutedEventHandler(this, &SimpleBank::AccountScreen::TransButtonClick);
			sp_TransferList->Children->Append(btn);
		}
	}

}

void SimpleBank::AccountScreen::bt_createStud_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	BankAccount^ Test1 = ref new BankAccount(EDat::AccountType::STUDENT, ++DATA::m_NextAccountNum, 0, 2000);
	m_CurProf->AddAccount(Test1);

	pbx_AddAccnt->IsOpen = false;
	UpdateAccountsView();
}


void SimpleBank::AccountScreen::bt_createSave_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	BankAccount^ Test1 = ref new BankAccount(EDat::AccountType::SAVING, ++DATA::m_NextAccountNum, 0, 0);
	m_CurProf->AddAccount(Test1);

	pbx_AddAccnt->IsOpen = false;
	UpdateAccountsView();
}


void SimpleBank::AccountScreen::bt_createCurr_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	BankAccount^ Test1 = ref new BankAccount(EDat::AccountType::CURRENT, ++DATA::m_NextAccountNum, 0, 500);
	m_CurProf->AddAccount(Test1);

	pbx_AddAccnt->IsOpen = false; 
	UpdateAccountsView();
}


void SimpleBank::AccountScreen::bt_TransAccept_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (m_CurAcc_trans != nullptr)
	{
		m_CurAcc->MakePayment(m_CurAcc_trans, stof(Utilities::convert_plat_string(tb_transAmount->Text)));

		UpdateCurrentAccount();
		pbx_Transfer->IsOpen = false;
		m_CurAcc_trans = nullptr;
	}
}


void SimpleBank::AccountScreen::bt_TransCancel_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	pbx_Transfer->IsOpen = false;
	m_CurAcc_trans = nullptr;
}


void SimpleBank::AccountScreen::bt_PaymentAccept_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	bool Finished = false;
	int AccNum = stoi(Utilities::convert_plat_string(tb_PaymentAccNum->Text));
	for (int i = 0; i < DATA::m_Profiles->Size; i++)
	{
		BankProfile^ CurrentProf = DATA::m_Profiles->GetAt(i);
		for (int j = 0; j < CurrentProf->GetAccountSize(); j++)
		{
			BankAccount^ CurrentAcc = CurrentProf->GetAccount(j);
			if (CurrentAcc->GetAccNumber() == AccNum)
			{
				m_CurAcc->MakePayment(CurrentAcc, stof(Utilities::convert_plat_string(tb_PaymentAmount->Text)));

				UpdateCurrentAccount();
				Finished = true;
				break;
			}
		}
		if (Finished)
			break;
	}

	pbx_MakePayment->IsOpen = false;
}


void SimpleBank::AccountScreen::bt_PaymentCancel_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	pbx_MakePayment->IsOpen = false;
}