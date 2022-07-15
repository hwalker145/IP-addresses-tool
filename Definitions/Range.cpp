#include "../Includes/Range.h"

bool Range::isValid()
{
	size_t chunks = 0;
	size_t chsize = 0;
	size_t chindex = -1;

	if (!getMask())
	{
		// log something about this
		return true;
	}

	if (getAddress()->getVersion() == 6)
	{
		chunks = 8;
		chsize = 16;
	}
	else if (getAddress()->getVersion() == 4)
	{
		chunks = 4;
		chsize = 8;
	}
	else
	{
		// maybe include a logging function?
		throw std::runtime_error("No version found for IP address range.\n");
	}

	chindex = (getMask() - 1) / chsize;

	for (size_t i = chindex + 1; i < chunks; i++)
	{
		if (getAddress()->getChunk(i))
		{
			return false;
		}
	}

	std::bitset<16> chSet(getAddress()->getChunk(chindex));
	for (size_t i = getMask() % chsize; i < chsize; i++)
	{
		if (chSet[i])
		{
			return false;
		}
	}
	return true;
}
