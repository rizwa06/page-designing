#pragma once

#include <vector>
#include "BankProfile.h"
#include <collection.h>

#ifndef Test
#define Test

namespace DATA
{
	extern Platform::Collections::Vector<BankProfile^>^ m_Profiles;

	//Use to keep track of account numbers so each new account will get a unique account number
	extern int m_NextAccountNum;
}

#endif