#include "Account.h"

Account::Account()
{
	//Empty
}

Account::Account(const AccountType & AccType, const std::string & Name, const unsigned int & AccNum, const float & Balence, const float & OverDraft) :
	m_AccountType(AccType), m_Name(Name), m_AccountNumber(AccNum), m_Balance(Balence), m_OverdraftLimit(OverDraft)
{
	//Empty
}

Account::~Account()
{
	//Empty
}

void Account::MakePayment(Account * Other, float Value)
{
	//Add amount to the other account
	Other->Deposit(Value, true);

	//Remove the amount from this account
	Withdraw(-Value, true);

	//Add Activity
	AddActivity(Activity(ActivityType::MADEPAYMENT, Other, Value));
	Other->AddActivity(Activity(ActivityType::RECEIVEDPAYMENT, Other, Value));
}

inline bool Account::Withdraw(float Value, bool NoActivity)
{
	//Do Transaction
	if ((m_Balance - Value) >= (0 - m_OverdraftLimit))
	{
		ModifyBalance(-Value);

		//Add Activity
		if (!NoActivity)
			AddActivity(Activity(ActivityType::WITHDRAW, this, Value));
	}
	else
		return false;
}

inline void Account::Deposit(float Value, bool NoActivity)
{
	//Do Transaction
	ModifyBalance(Value);

	//Add Activity
	if (!NoActivity)
		AddActivity(Activity(ActivityType::DEPOSIT, this, Value));
}