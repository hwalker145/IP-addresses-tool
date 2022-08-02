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

#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>

class Address {
public:
	Address()
	{
		address = nullptr;
		version = 0;
	}

	Address(_TSTR);

	_TSTR asString() const;

	~Address()
	{
		delete address;
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
		#ifdef _UNICODE
			constexpr _TCHAR _TCOLON = L':';
			constexpr _TCHAR _TCOMMA = L',';
		#else 
			constexpr _TCHAR _TCOLON = ':';
			constexpr _TCHAR _TCOMMA = ',';
		#endif

		for (int i = 1; i < 5; i++)
		{
			if (str[i] == _TCOMMA) { return 4; };
			if (str[i] == _TCOLON) { return 6; };
		}
		return 0;
	}

	void setVersion(int v) { version = v; };

	int version;
	size_t* address;
};

#endif