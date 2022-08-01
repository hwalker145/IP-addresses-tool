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

	Address(std::string);

	std::string asString() const;

	~Address()
	{
		delete address;
		address = nullptr;
		version = 0;
	}

	int getVersion() const { return version; };
	size_t getChunk(int c) const { return address[c]; };
	void setChunk(int c, int ci) { address[ci] = c; };

	int addCmp(Address*);

private:
	int checkVersion(std::string str)
	{
		for (int i = 1; i < 5; i++)
		{
			if (str[i] == '.') { return 4; };
			if (str[i] == ':') { return 6; };
		}
		return 0;
	}

	void setVersion(int v) { version = v; };

	int version;
	size_t* address;
};

#endif