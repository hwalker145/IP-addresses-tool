#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <cmath>
#include <sstream>
#include <string>

using std::wstring;
using std::getline;
using std::wostringstream;
using std::wistringstream;
using std::stoi;

class Address {
public:
	Address()
	{
		address = nullptr;
		version = 0;
	}

	Address(wstring);

	wstring asString() const;

	~Address()
	{
		delete address;
		address = nullptr;
		version = 0;
	}

private:
	int checkVersion(wstring str)
	{
		for (int i = 1; i < 5; i++)
		{
			if (str[i] == L'.') { return 4; };
			if (str[i] == L':') { return 6; };
		}
		return 0;
	}

	wstring getChunk(int c) const { return address[c]; };
	int getVersion() const { return version; };

	void setChunk(wstring c, int ci) { address[ci] = c; };
	void setVersion(int v) { version = v; };

	int version;
	wstring* address;
};

#endif