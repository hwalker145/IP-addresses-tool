#ifndef RANGE_H
#define RANGE_H

#include "AddressV4.h"

template <class T>
class Range {
public:
    bool isValid();
private:
    int mask;
    T address;
};

#endif