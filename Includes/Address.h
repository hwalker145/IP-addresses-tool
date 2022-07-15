/*****************************************************************//**
 * \file   Address.h
 * \brief  
 * 
 * \author walkerh4
 * \date   July 2022
 *********************************************************************/

#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <stdexcept>
#include <iomanip>

class Address {
public:
	Address()
	{
		address = nullptr;
		version = 0;
	}

	Address(std::wstring);

	std::wstring asString() const;

	~Address()
	{
		delete address;
		address = nullptr;
		version = 0;
	}

	size_t getVersion() const { return version; };
	size_t getChunk(size_t c) const { return address[c]; };

private:
	int checkVersion(std::wstring str)
	{
		for (size_t i = 1; i < 5; i++)
		{
			if (str[i] == L'.') { return 4; };
			if (str[i] == L':') { return 6; };
		}
		return 0;
	}

	void setChunk(size_t c, size_t ci) { address[ci] = c; };
	void setVersion(size_t v) { version = v; };

	int version;
	size_t* address;
};

#endif