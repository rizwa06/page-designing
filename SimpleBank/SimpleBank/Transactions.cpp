#include "pch.h"
#include "Transactions.h"


Transaction::Transaction(EDat::ActivityType Type, int OtherAccountNum , float Amount)
{
	m_AccType = Type;
	m_OtherAccountNum = OtherAccountNum;
	m_Amount = Amount;
}

Platform::String ^ Transaction::GetActivityType()
{
	Platform::String^ AcType = "Test";
	switch (m_AccType)
	{
		case EDat::ActivityType::DEPOSIT:
			AcType = "Deposit";
		break;
		case EDat::ActivityType::MADEPAYMENT:
				AcType = "Made Payment";
		break;
		case EDat::ActivityType::RECEIVEDPAYMENT:
			AcType = "Received Payment";
		break;
		case EDat::ActivityType::WITHDRAW:
			AcType = "Withdraw";
		break;
	}
	return AcType;
}

bool Transaction::IsPayment()
{
	if ((m_AccType == EDat::ActivityType::MADEPAYMENT) || (m_AccType == EDat::ActivityType::RECEIVEDPAYMENT))
		return true;
	else
		return false;
}