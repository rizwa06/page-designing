#include <iostream>

//Custom Includes
#include "Account.h"

//Main
int main()
{
	Account One = Account(AccountType::SAVING, "Jeremy", 12231223, 13231.12f, 0);
	Account Two = Account(AccountType::CURRENT, "Linda", 32233273, 131.00f, 1000);
	Account Three = Account(AccountType::CURRENT, "Johnny", 94269279, 831.00f, 2000);

	One.Deposit(122);
	One.MakePayment(&Two, 45);
	Two.MakePayment(&One, 12);
	Two.Withdraw(12);

	bool Status = Three.Withdraw(2830);
	if(Status)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;

	return 0;
}