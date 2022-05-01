#ifndef RANGE_H
#define RANGE_H

#include "AddressV4.h"

template <class T>
class Range {
public:
    bool isValid();

    void setMask(int msk) {mask = msk;};
    void setaddress(*T add) {address = add;};

    *T getAddress() {return address;};
    *T getMaxAddress() {return maxAddress;};
    int getMask() {return mask;};

private:
    int mask;
    *T address, maxAddress;
};

#endif