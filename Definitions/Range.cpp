#include "../Includes/Range.h"

bool Range::isValid()
{

	std::bitset<16> ranSet(getAddress()->getChunk((getMask() - 1) / 4));
}
