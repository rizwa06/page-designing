#pragma once

#include <string>
#include <vector>

enum AccountType
{
	SAVING,
	CURRENT,
	STUDENT
};

enum ActivityType
{
	WITHDRAW,
	DEPOSIT,
	MADEPAYMENT,
	RECEIVEDPAYMENT
};
class Account;
struct Activity
{
	ActivityType AccType;
	Account* OtherAccount;
	float Amount;

	Activity(ActivityType Type, Account* SOtherAccount, float SAmount)
	{
		AccType = Type;
		OtherAccount = SOtherAccount;
		Amount = SAmount;
	}
};

class Account
{
public:
	//Constructors
	Account();
	Account(const AccountType& AccType, const std::string& Name, const unsigned int& AccNum, const float& Balence, const float& OverDraft);
	//Destructor
	~Account();

	//Functions
	void MakePayment(Account* Other, float Value);

	//Getters
	inline std::string GetName() { return m_Name; };
	inline unsigned int GetAccountNum() { return m_AccountNumber; };
	inline float GetBalance() { return m_Balance; };
	inline float GetOverdraftLimit() { return m_OverdraftLimit; };

	//Setters
	inline bool Withdraw(float Value, bool NoActivity = false);
	inline void Deposit(float Value, bool NoActivity = false);

private:
	//Function
	inline void ModifyBalance(float Value) { m_Balance += Value; }; //Pass negative number to decrease balence
	inline void AddActivity(const Activity& Activ) { m_RecentActivity.push_back(Activ); }

	//Member Variables
	AccountType m_AccountType;
	std::string m_Name;
	unsigned int m_AccountNumber;
	float m_Balance;
	float m_OverdraftLimit;

	std::vector<Activity> m_RecentActivity = std::vector<Activity>();
};