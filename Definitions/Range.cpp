#include "../Includes/Range.h"

using std::cerr;

template<typename T>
Range<T>::Range()
{
    int version = 0;
    if(typeid(T).name() == AddressV4)
    {
        version = 4;
    }
    else if(typeid(T).name() == AddressV6)
    {
        version = 6;
    }
    else
    {
        cerr << "Coder input invalid Range template type.\n"
             << "Use either AddressV4 or AddressV6.";
    }
}