#include "../Includes/IPAddress.h"

int main()
{
    Range<AddressV6> *A = new Range<AddressV6>("0:ee:ee:ee:0:0:0:0/10");

    cout << "Stub 0000\n";

    cout << "The min address is: " << A->getAddress()->getChunkString(0) << "\n"
         << "The subnet size is: " << A->getMask() << "\n"
         << "The validity of this range is: " << Range<AddressV6>::isValid(A) << '\n';

    return 0;
}