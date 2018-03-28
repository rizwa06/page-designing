#include "pch.h"
#include "Data.h"
namespace DATA
{
	Platform::Collections::Vector<BankProfile^>^ m_Profiles = ref new Platform::Collections::Vector<BankProfile^>();
	int m_NextAccountNum = 0;
}