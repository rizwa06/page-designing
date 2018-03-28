//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "AccountScreen.xaml.h"
#include "Utils.h"
#include <tuple>
#include <utility>

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

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
}

void SimpleBank::MainPage::pb_password_PasswordChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (pb_password->Password != "")
		m_not_empty_pass = true;
	else
		m_not_empty_pass = false;
	UpdateButtonEn();
}

void SimpleBank::MainPage::tb_userid_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	if (tb_userid->Text != "" && validID(Utilities::convert_plat_string(tb_userid->Text)))
		m_valid_id = true;
	else
		m_valid_id = false;
	UpdateButtonEn();
}

void SimpleBank::MainPage::UpdateButtonEn()
{
	if (m_not_empty_pass && m_valid_id)
		bt_login->IsEnabled = true;
	else
		bt_login->IsEnabled = false;
}

bool SimpleBank::MainPage::validID(const std::string & id_code)
{
	if (tb_userid->Text->Length() == 6)
	{
		lab_iderror->Text = "";
		return true;
	}
	else
	{
		lab_iderror->Text = "Invalid ID";
		return false;
	}
}

void SimpleBank::MainPage::tb_userid_KeyDown(Platform::Object^ sender, Windows::UI::Xaml::Input::KeyRoutedEventArgs^ e)
{
	
}

void SimpleBank::MainPage::bt_login_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	bool Found = false;
	for (int i = 0; i < DATA::m_Profiles->Size; i++)
		if (Utilities::convert_plat_string(tb_userid->Text) == std::to_string(DATA::m_Profiles->GetAt(i)->GetUserID()))
		{
			Found = true;
			if (pb_password->Password == DATA::m_Profiles->GetAt(i)->GetPassword())
			{
				//DATA::Payload^ Temp = ref new DATA::Payload(DATA::m_Profiles, DATA::m_Profiles->GetAt(i));
				this->Frame->Navigate(SimpleBank::AccountScreen::typeid, DATA::m_Profiles->GetAt(i));
			}
			else
				lab_passerror->Text = "Invalid Password";
		}
	if(!Found)
		lab_iderror->Text = "User does not exist";
}