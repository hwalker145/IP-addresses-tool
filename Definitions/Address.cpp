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
Address::Address(std::string str)
{
	version = checkVersion(str);

	int chunks = 0; 
	int base = 0;
	char del = '\0';

	if (version == 4) { chunks = 4; del = '.'; base = 10; }
	else if (version == 6) { chunks = 8; del = ':'; base = 16; }

	address = new size_t[chunks];

	std::istringstream istr(str);
	std::string temp;

	for (int i = 0; i < chunks - 1; i++)
	{
		getline(istr, temp, del);
		address[i] = (size_t)stoi(temp, nullptr, base);
	}
	getline(istr, temp);
	address[chunks - 1] = (size_t)stoi(temp, nullptr, base);
}

std::string Address::asString() const
{
	std::ostringstream ostr;

	int chunks = 0;
	char del = L'\0';

	if (version == 4) { chunks = 4; del = L'.'; }
	else if (version == 6) { chunks = 8; del = L':'; ostr << std::hex; }


	for (int i = 0; i < chunks - 1; i++)
	{
		ostr << address[i] << del;
	}
	ostr << address[chunks - 1];

	return ostr.str();
}
