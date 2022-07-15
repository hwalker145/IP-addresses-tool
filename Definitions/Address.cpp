#include "../Includes/Address.h"
/*****************************************************************//**
 * \file   Address.cpp
 * \brief  Class to contain IP address; definition
 * 
 * 
 * \author walkerh4
 * \date   July 2022
 *********************************************************************/

/**
 * Constructor with wstring for address class
 * 
 * param str is the wstring
 */
Address::Address(std::wstring str)
{
	version = checkVersion(str);

	size_t chunks = 0; 
	size_t base = 0;
	wchar_t del = L'\0';

	if (version == 4) { chunks = 4; del = L'.'; base = 10; }
	else if (version == 6) { chunks = 8; del = L':'; base = 16; }

	address = new size_t[chunks];

	std::wistringstream istr(str);
	std::wstring temp;

	for (size_t i = 0; i < chunks; i++)
	{
		getline(istr, temp, del);
		address[i] = (size_t)stoi(temp, nullptr, base);
	}
}

std::wstring Address::asString() const
{
	std::wostringstream ostr;

	size_t chunks = 0;
	wchar_t del = L'\0';

	if (version == 4) { chunks = 4; del = L'.'; }
	else if (version == 6) { chunks = 8; del = L':'; }

	for (size_t i = 0; i < chunks - 1; i++)
	{
		ostr << address[i] << del;
	}
	ostr << address[chunks];

	return ostr.str();
}
