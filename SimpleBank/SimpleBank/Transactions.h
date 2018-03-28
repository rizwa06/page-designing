#pragma once

namespace EDat
{
	public enum class AccountType
	{
		SAVING,
		CURRENT,
		STUDENT
	};

	public enum class ActivityType
	{
		WITHDRAW,
		DEPOSIT,
		MADEPAYMENT,
		RECEIVEDPAYMENT
	};
}

ref class Transaction sealed
{
public:
	Transaction(EDat::ActivityType Type, int OtherAccountNum, float Amount);

	//Getters
	Platform::String^ GetActivityType();
	inline int GetOthAccNum() { return m_OtherAccountNum; };
	inline float GetAmount() { return m_Amount; };

	bool IsPayment();

private:
	EDat::ActivityType m_AccType;
	int m_OtherAccountNum;
	float m_Amount;
};