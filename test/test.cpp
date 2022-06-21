#include "../Includes/IPAddress.h"

int main()
{
    Range<AddressV6> *A = new Range<AddressV6>("0:ee:ee:ee:0:0:0:0000/63");

    bool AValid = Range<AddressV6>::isValid(A);

    cout << "The min address is: " << A->getAddress()->getString() << '\n'
         << "The subnet size is: " << A->getMask() << '\n'
         << "The validity of this range is: " << AValid << '\n';

    return 0;
}