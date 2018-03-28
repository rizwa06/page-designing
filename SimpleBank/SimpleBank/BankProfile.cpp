#include "pch.h"
#include "BankProfile.h"

BankProfile::BankProfile(unsigned int UserID, Platform::String^ Password, Platform::String^ Name) :
	m_UserID(UserID), m_Password(Password), m_Name(Name)
{
	//Empty
}

void BankProfile::AddAccount(BankAccount^ Acc)
{
	m_Accounts->Append(Acc);
}

BankAccount ^ BankProfile::FindAccount(int AccountNumber)
{
	for (int i = 0; i < m_Accounts->Size; i++)
		if (AccountNumber == m_Accounts->GetAt(i)->GetAccNumber())
			return m_Accounts->GetAt(i);
}