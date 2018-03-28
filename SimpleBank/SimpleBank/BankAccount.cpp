#include "pch.h"
#include "BankAccount.h"

BankAccount::BankAccount(EDat::AccountType AccType, int AccNum, float Balance, float Overdraft) :
	m_AccType(AccType), m_AccountNumber(AccNum), m_Balance(Balance), m_OverdraftLimit(Overdraft)
{
	//Empty
}

Platform::String^ BankAccount::GetAccTypeStr()
{
	Platform::String^ AcType = "Test";
	switch (m_AccType)
	{
		case EDat::AccountType::CURRENT:
			AcType = "Current";
		break;
		case EDat::AccountType::SAVING:
			AcType = "Saving";
		break;
		case EDat::AccountType::STUDENT:
			AcType = "Student";
		break;
	}
	return AcType;
}

void BankAccount::MakePayment(BankAccount^ Other, float Value)
{
	//Add amount to the other account
	Other->Deposit(Value, true);

	//Remove the amount from this account
	Withdraw(-Value, true);

	//Add Activity
	AddActivity(ref new Transaction(EDat::ActivityType::MADEPAYMENT, Other->GetAccNumber(), Value));
	Other->AddActivity(ref new Transaction(EDat::ActivityType::RECEIVEDPAYMENT, Other->GetAccNumber(), Value));
}

bool BankAccount::Withdraw(float Value, bool NoActivity)
{
	//Do Transaction
	if ((m_Balance - Value) >= (0 - m_OverdraftLimit))
	{
		ModifyBalance(-Value);

		//Add Activity
		if (!NoActivity)
			AddActivity(ref new Transaction(EDat::ActivityType::WITHDRAW, -1, Value));
	}
	else
		return false;
}

void BankAccount::Deposit(float Value, bool NoActivity)
{
	//Do Transaction
	ModifyBalance(Value);

	//Add Activity
	if (!NoActivity)
		AddActivity(ref new Transaction(EDat::ActivityType::DEPOSIT, -1, Value));
}