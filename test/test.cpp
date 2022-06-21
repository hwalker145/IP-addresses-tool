#include "../Includes/IPAddress.h"

int main()
{
    Range<AddressV6>* A = new Range<AddressV6>("0000:0000:0000:0:0:0:00ee:000e/3");

    cout << "A Range object mask: " << A->getMask() << "\n"
         << "A Range object address chunk[2]: " << A->getAddress()->getChunkString(2)
         << "\n";   

    return 0;
}