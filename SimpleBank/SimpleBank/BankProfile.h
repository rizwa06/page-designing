#pragma once

#include <string>
#include <vector>
#include <collection.h>
#include <algorithm>

#include "BankAccount.h"

ref class BankProfile sealed
{
public:

	BankProfile(unsigned int UserID, Platform::String^ Password, Platform::String^ Name);

	void AddAccount(BankAccount^ Acc);

	//Getters
	inline unsigned int GetUserID() { return m_UserID; }
	inline Platform::String^ GetPassword() { return m_Password; }
	inline Platform::String^ GetName() { return m_Name; }

	inline int GetAccountSize() { return m_Accounts->Size; }
	inline BankAccount^ GetAccount(int Pos) { return m_Accounts->GetAt(Pos); }

	BankAccount^ FindAccount(int AccountNumber);

	//Setters
	inline void SetUserID(unsigned int UserID) { m_UserID = UserID; }
	inline void SetPassword(Platform::String^ Password) { m_Password = Password; }
	inline void SetName(Platform::String^ Name) { m_Name = Name; }

private:
	unsigned int m_UserID;
	Platform::String^ m_Password;

	Platform::String^ m_Name;

	Platform::Collections::Vector<BankAccount^>^ m_Accounts = ref new Platform::Collections::Vector<BankAccount^>();
};