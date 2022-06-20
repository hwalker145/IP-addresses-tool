#include "../Includes/Range.h"

using std::cerr;

Range<AddressV4>::Range()
{
    setAddress(new AddressV4);
    setMask(0);
}

Range<AddressV6>::Range()
{
    setAddress(new AddressV6);
    setMask(0);
}