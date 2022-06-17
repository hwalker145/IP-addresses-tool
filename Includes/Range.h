#ifndef RANGE_H
#define RANGE_H

#include "AddressV4.h"

template <typename T>
class Range {
public:
    bool isValid();

    void setaddress(*T add) {address = add;};
    *T getAddress() const {return address;};
    *T getMaxAddress() const {return maxAddress;};

    void setMask(int msk) {mask = msk;};
    int getMask() const {return mask;};

private:
    int mask;
    *T address, maxAddress;
};

#endif