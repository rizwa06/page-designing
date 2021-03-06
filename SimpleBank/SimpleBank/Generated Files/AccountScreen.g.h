﻿#pragma once
//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------


namespace Windows {
    namespace UI {
        namespace Xaml {
            namespace Controls {
                ref class Grid;
                ref class TextBlock;
                ref class Button;
                ref class TextBox;
                ref class StackPanel;
            }
        }
    }
}
namespace Windows {
    namespace UI {
        namespace Xaml {
            namespace Controls {
                namespace Primitives {
                    ref class Popup;
                }
            }
        }
    }
}

namespace SimpleBank
{
    [::Windows::Foundation::Metadata::WebHostHidden]
    partial ref class AccountScreen : public ::Windows::UI::Xaml::Controls::Page, 
        public ::Windows::UI::Xaml::Markup::IComponentConnector,
        public ::Windows::UI::Xaml::Markup::IComponentConnector2
    {
    public:
        void InitializeComponent();
        virtual void Connect(int connectionId, ::Platform::Object^ target);
        virtual ::Windows::UI::Xaml::Markup::IComponentConnector^ GetBindingConnector(int connectionId, ::Platform::Object^ target);
    
    private:
        void UnloadObject(::Windows::UI::Xaml::DependencyObject^ dependencyObject);
        void DisconnectUnloadedObject(int connectionId);
    
    private:
        bool _contentLoaded;
    
    
        private: ::Windows::UI::Xaml::Controls::Grid^ ___no_name_;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ lab_UserName;
        private: ::Windows::UI::Xaml::Controls::Button^ bt_Logout;
        private: ::Windows::UI::Xaml::Controls::Primitives::Popup^ pbx_AddAccnt;
        private: ::Windows::UI::Xaml::Controls::Primitives::Popup^ pbx_Transfer;
        private: ::Windows::UI::Xaml::Controls::Primitives::Popup^ pbx_MakePayment;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ lab_OverdraftLimit;
        private: ::Windows::UI::Xaml::Controls::Button^ bt_Withdraw;
        private: ::Windows::UI::Xaml::Controls::TextBox^ tb_Withdraw;
        private: ::Windows::UI::Xaml::Controls::Button^ bt_Deposit;
        private: ::Windows::UI::Xaml::Controls::TextBox^ tb_Deposit;
        private: ::Windows::UI::Xaml::Controls::Button^ bt_MakePayment;
        private: ::Windows::UI::Xaml::Controls::Button^ bt_Transfer;
        private: ::Windows::UI::Xaml::Controls::StackPanel^ sp_ActivityLogLeft;
        private: ::Windows::UI::Xaml::Controls::StackPanel^ sp_ActivityLogCen;
        private: ::Windows::UI::Xaml::Controls::StackPanel^ sp_ActivityLogRight;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ lab_Balance;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ lab_AccNumber;
        private: ::Windows::UI::Xaml::Controls::StackPanel^ sp_AccountList;
        private: ::Windows::UI::Xaml::Controls::Button^ bt_AddAccount;
        private: ::Windows::UI::Xaml::Controls::Grid^ grd_Payment;
        private: ::Windows::UI::Xaml::Controls::StackPanel^ sp_PaymentMain;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ lab_PaymentAccNum;
        private: ::Windows::UI::Xaml::Controls::TextBox^ tb_PaymentAccNum;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ lab_PaymentAmount;
        private: ::Windows::UI::Xaml::Controls::TextBox^ tb_PaymentAmount;
        private: ::Windows::UI::Xaml::Controls::Button^ bt_PaymentAccept;
        private: ::Windows::UI::Xaml::Controls::Button^ bt_PaymentCancel;
        private: ::Windows::UI::Xaml::Controls::Grid^ grd_Transfer;
        private: ::Windows::UI::Xaml::Controls::StackPanel^ sp_TransferMain;
        private: ::Windows::UI::Xaml::Controls::StackPanel^ sp_TransferList;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ lab_TransAmount;
        private: ::Windows::UI::Xaml::Controls::TextBox^ tb_transAmount;
        private: ::Windows::UI::Xaml::Controls::Button^ bt_TransAccept;
        private: ::Windows::UI::Xaml::Controls::Button^ bt_TransCancel;
        private: ::Windows::UI::Xaml::Controls::Button^ bt_Close;
        private: ::Windows::UI::Xaml::Controls::Button^ bt_createStud;
        private: ::Windows::UI::Xaml::Controls::Button^ bt_createSave;
        private: ::Windows::UI::Xaml::Controls::Button^ bt_createCurr;
    };
}

