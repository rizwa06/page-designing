#pragma once

#include <string>
#include <vector>
#include <collection.h>
#include <algorithm>

#include "Transactions.h"

ref class BankAccount sealed
{
public:
	BankAccount(EDat::AccountType AccType, int AccNum, float Balance, float Overdraft);

	//Getters
	inline int GetAccNumber() { return m_AccountNumber; }
	inline float GetBalance() { return m_Balance; }
	inline float GetOverdraftLimit() { return m_OverdraftLimit; }


	Platform::String^ GetAccTypeStr();

	void MakePayment(BankAccount ^ Other, float Value);


	bool Withdraw(float Value, bool NoActivity);
	void Deposit(float Value, bool NoActivity);

	inline int GetActivitySize() { return m_Activity->Size; }
	inline Transaction^ GetActivityAt(int Pos) { return m_Activity->GetAt(Pos); }

	inline void AddActivity(Transaction^ Trans) { m_Activity->Append(Trans); }


private:

	inline void ModifyBalance(float Value) { m_Balance += Value; }; //Pass negative number to decrease balence

	EDat::AccountType m_AccType;
	int m_AccountNumber;
	float m_Balance;
	float m_OverdraftLimit;

	Platform::Collections::Vector<Transaction^>^ m_Activity = ref new Platform::Collections::Vector<Transaction^>();
}; 