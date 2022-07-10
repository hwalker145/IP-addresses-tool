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
Address::Address(wstring str)
{
	version = checkVersion(str);

	int chunks = 0; 
	wchar_t del = L'\0';

	if (version == 4) { chunks = 4; del = L'.'; }
	else if (version == 6) { chunks = 8; del = L':'; }

	address = new wstring[chunks];

	wistringstream istr(str);

	for (int i = 0; i < chunks; i++)
	{
		getline(istr, address[i], del);
	}
}

wstring Address::asString() const
{
	wostringstream ostr;

	int chunks = 0;
	wchar_t del = L'\0';

	if (version == 4) { chunks = 4; del = L'.'; }
	else if (version == 6) { chunks = 8; del = L':'; }

	for (int i = 0; i < chunks - 1; i++)
	{
		ostr << address[i] << del;
	}
	ostr << address[chunks];

	return ostr.str();
}
