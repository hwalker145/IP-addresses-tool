#ifndef RANGE_H
#define RANGE_H

#include <cmath>
#include "AddressV4.h"
#include "AddressV6.h"

template <typename T>
class Range {
public:
    // called before instantiation
    static bool isValid(T*, int);

    Range(); // kind of dumb to ever call this one.
    Range(string); // this one will be called most
    Range(T*, int); // this one will be used indirectly
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