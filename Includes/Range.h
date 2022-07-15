#ifndef RANGE_H
#define RANGE_H

#include <cmath>
#include <bitset>
#include "AddressV4.h"
#include "Address.h"
#include "AddressV6.h"

class Range {
public:
    // can be called statically
    bool isValid();

    Range() // pretty useless
    {
        setAddress(new Address);
        setMask(0);
    }

    Range(wstring str) // this one will be called most
    {
        wistringstream istr;
        istr.str(str);

        // used to pass in the address and mask
        wstring tempStr;
        size_t tempMsk;

        getline(istr, tempStr, L'/');
        istr >> tempMsk;

        setAddress(new Address(tempStr));
        setMask(tempMsk);
    }

    Address* findMax();

    void setAddress(Address* add) {address = add;};
    // a wrapper to use on the generated address from Range::findMax
    // not 100p necessary I guess

    void setMaxAddress(Address* add) {maxAddress = add;};
    Address* getAddress() const {return address;};
    Address* getMaxAddress() const {return maxAddress;};

    void setMask(size_t msk) {mask = msk;};
    size_t getMask() const {return mask;};

    ~Range()
    {
        delete address;
        delete maxAddress;

        address = nullptr;
        maxAddress = nullptr;
    }

private:
    size_t mask;
    Address *address, *maxAddress;
};

#endif