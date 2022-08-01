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
Address::Address(std::string str) {
	version = checkVersion(str);

	int chunks = 0; 
	int base = 0;
	char del = '\0';

	if (version == 4) { chunks = 4; del = '.'; base = 10; }
	else if (version == 6) { chunks = 8; del = ':'; base = 16; }

	address = new size_t[chunks];

	std::istringstream istr(str);
	std::string temp;

	for (int i = 0; i < chunks - 1; i++) {
		getline(istr, temp, del);
		address[i] = (size_t)stoi(temp, nullptr, base);
	}
	getline(istr, temp);
	address[chunks - 1] = (size_t)stoi(temp, nullptr, base);
}

std::string Address::asString() const {
	std::ostringstream ostr;

	int chunks = 0;
	char del = L'\0';

	if (version == 4) { chunks = 4; del = L'.'; }
	else if (version == 6) { chunks = 8; del = L':'; ostr << std::hex; }


	for (int i = 0; i < chunks - 1; i++) {
		ostr << address[i] << del;
	}
	ostr << address[chunks - 1];

	return ostr.str();
}

int Address::addCmp(Address* addPtr) {
	int chsize = 0;
	int chunks = 0;

	if (getVersion() == 6) { chunks = 8; chsize = 16; }
	else if (getVersion() == 4) { chunks = 4; chsize = 8; }
	else {
		throw std::runtime_error("No valid version found for IP address range.\n");
	}

	if(addPtr->getVersion() != getVersion()) {
		throw std::logic_error("Comparing addresses of different versions. Exiting\n");
	}

	for(int i = 0; i < chunks; i++) {
		if(getChunk(i) > addPtr->getChunk(i)) { return 1; }
		else if(getChunk(i) < addPtr->getChunk(i)) { return -1; }
	}

	return 0;
}
