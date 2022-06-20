#ifndef RANGE_H
#define RANGE_H

#include "AddressV4.h"
#include "AddressV6.h"

template <typename T>
class Range {
public:
    // called before instantiation
    static bool isValid(T*, int);

    Range();
    Range(T*, int);
    T* findMax();

    void setAddress(T* add) {address = add;};
    // a wrapper to use on the generated address from Range::findMax
    // not 100p necessary I guess

    void setMaxAddress(T* add) {maxAddress = add;};
    T* getAddress() const {return address;};
    T* getMaxAddress() const {return maxAddress;};

    void setMask(int msk) {mask = msk;};
    int getMask() const {return mask;};

private:
    int mask;
    T* address, maxAddress;
};

#endif