#include "../Includes/IPAddress.h"


int main()
{
    Range<AddressV4> *A = new Range<AddressV4>("1.255.8.0/15");

    bool AValid = Range<AddressV4>::isValid(A);

    cout << "The min address is: " << A->getAddress()->getString() << '\n'
         << "The subnet size is: " << A->getMask() << '\n'
         << "The validity of this range is: " << AValid << '\n';

    return 0;
}