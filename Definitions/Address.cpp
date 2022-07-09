#include "../Includes/Address.h"

/**
* 
*/
Address::Address(wstring str)
{
	version = checkVersion(str);

	int chunks; 
	wchar_t del;

	if (version == 4) { chunks = 4; del = L'.'; }
	else if (version == 6) { chunks = 8; del = L':'; }

	address = new wstring[chunks];

	wistringstream istr(str);

	for (int i = 0; i < chunks; i++)
	{
		getline(istr, address[i], del);
	}
}