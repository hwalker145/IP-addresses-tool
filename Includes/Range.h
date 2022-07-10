#ifndef RANGE_H
#define RANGE_H

#include <cmath>
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
        int tempMsk;

        getline(istr, tempStr, L'/');
        istr >> tempMsk;

        setAddress(new Address(tempStr));
        setMask(tempMsk);
    }

    Range(Address* ptr, int msk) // this one will be used indirectly
    {
        setAddress(ptr);
        setMask(msk);
    }

    Address* findMax();

    void setAddress(Address* add) {address = add;};
    // a wrapper to use on the generated address from Range::findMax
    // not 100p necessary I guess

    void setMaxAddress(Address* add) {maxAddress = add;};
    Address* getAddress() const {return address;};
    Address* getMaxAddress() const {return maxAddress;};

    void setMask(int msk) {mask = msk;};
    int getMask() const {return mask;};

    ~Range()
    {
        delete address;
        delete maxAddress;

        address = nullptr;
        maxAddress = nullptr;
    }

private:
    int mask;
    Address *address, *maxAddress;
};

#endif