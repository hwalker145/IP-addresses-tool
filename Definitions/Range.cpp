#include "../Includes/Range.h"

Address* Range::findMax() {
	int chindex = -1;
	int chsize = 0;
	int chunks = 0;

	if (getAddress()->getVersion() == 6) { chunks = 8; chsize = 16; }
	else if (getAddress()->getVersion() == 4) { chunks = 4; chsize = 8;	}
	else {
		throw std::runtime_error("No valid version found for IP address range.\n");
	}

	Address* add = new Address(getAddress()->asString());

	chindex = (getMask() - 1) / chsize;

	add->setChunk(add->getChunk(chindex) + (1 << (chsize - (getMask() % chsize))) - 1, chindex);

	for(int i = chindex + 1; i < chunks; i++) {
		add->setChunk((1 << chsize) - 1, i);
	}

	return add;
}

bool Range::isValid() {
	int chunks = 0;
	int chsize = 0;
	int chindex = -1;

	if (!getMask())
	{
		return true;
	}

	if (getAddress()->getVersion() == 6) { chunks = 8; chsize = 16; }
	else if (getAddress()->getVersion() == 4) { chunks = 4; chsize = 8;	}
	else {
		throw std::runtime_error("No valid version found for IP address range.\n");
	}

	chindex = (getMask() - 1) / chsize;

	for (int i = chindex + 1; i < chunks; i++) {
		if (getAddress()->getChunk(i)) { return false; }
	}

	if (getAddress()->getChunk(chindex) & ((1 << (chsize - (getMask() % chsize))) - 1)) {
		return false;
	}
	return true;
}
