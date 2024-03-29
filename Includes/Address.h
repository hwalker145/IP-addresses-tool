/*****************************************************************//**
 * \file   Address.h
 * \brief  
 * 
 * \author walkerh4
 * \date   July 2022
 *********************************************************************/

#ifndef ADDRESS_H
#define ADDRESS_H

#include "setup.h"


class Address {
public:
	Address()
	{
		address = nullptr;
		version = 0;
	}

	Address(const _TCHAR*);

	const _TCHAR* asString() const;

	~Address()
	{
		delete[] address;
		address = nullptr;
		version = 0;
	}

	int getVersion() const { return version; };
	size_t getChunk(int c) const { return address[c]; };
	void setChunk(size_t c, int ci) { address[ci] = c; };

	int addCmp(Address*);

private:
	int checkVersion(_TSTR str)
	{
		for (int i = 1; i < 5; i++)
		{
			if (str[i] == _TPERIOD) { setVersion(4); return 4; };
			if (str[i] == _TCOLON) { setVersion(6); return 6; };
		}
		return 0;
	}

	void setVersion(int v) { version = v; };

	int version;
	size_t* address;
};

#endif