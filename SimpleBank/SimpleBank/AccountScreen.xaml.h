//
// AccountScreen.xaml.h
// Declaration of the AccountScreen class
//

#pragma once

#include "AccountScreen.g.h"

//#include "MainPage.xaml.h"

#include "Utils.h"
#include "BankAccount.h"
#include "BankProfile.h"

#include "Data.h"

namespace SimpleBank
{
	public ref class AccountScreen sealed
	{
	public:
		AccountScreen();
		void  OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
		void AccountBtnClick(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
		void TransButtonClick(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);

	private:
		void bt_AddAccount_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void bt_Logout_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);


		void bt_Close_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

		void AddAccountButton(Platform::String^ Text);

		void UpdateCurrentAccount();
		void UpdateAccountsView();


		//DATA::Payload^ m_Payload;
		//Platform::Collections::Vector<BankProfile^>^ m_CurProfs;
		BankProfile^ m_CurProf;
		BankAccount^ m_CurAcc;
		BankAccount^ m_CurAcc_trans = nullptr;

		void bt_Deposit_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void bt_Withdraw_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void bt_MakePayment_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void bt_Transfer_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void bt_createStud_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void bt_createSave_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void bt_createCurr_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void bt_TransAccept_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void bt_TransCancel_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void bt_PaymentAccept_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void bt_PaymentCancel_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}