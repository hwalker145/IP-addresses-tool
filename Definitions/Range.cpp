#include "../Includes/Range.h"

bool Range::isValid()
{
	int bitsInChunk = 0; // bits of data in each chunk
	int chunks = 0; // total amount of chunks in Address
	int version = 0; // IPV
	int zeroChunk = 0; // chunk expected to be all zeros

	if (getAddress()->getVersion() == 4)
	{
		if (getMask() == 32)
		{
			return true;
		}
		else if (getMask() > 32)
		{
			return false;
		}
		bitsInChunk = 8;
		chunks = 4;
		zeroChunk = ((getMask() - 1) / bitsInChunk) + 1;
	}
	else if (getAddress()->getVersion() == 6)
	{
		if (getMask() == 128)
		{
			return true;
		}
		else if (getMask() > 128)
		{
			return false;
		}
		bitsInChunk = 16;
		chunks = 8;
		zeroChunk = ((getMask() - 1) / bitsInChunk) + 1;
	}
	else
	{
		throw std::runtime_error("No valid IP version detected. Exiting\n");
	}

	for (int i = chunks - 1; i >= zeroChunk; i--)
	{
		if (stoi(getAddress()->getChunk(i)) != 0)
		{
			return false;
		}
	}

	if (zeroChunk == 0)
	{
		return true;
	}

	// zeroChunk between (1 : chunks)
	if (stoi(getAddress()->getChunk(zeroChunk - 1)) % (int)pow(2, (bitsInChunk - (getMask() % bitsInChunk))))
	{
		return false;
	}

	return true;
}