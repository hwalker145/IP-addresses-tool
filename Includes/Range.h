#ifndef RANGE_H
#define RANGE_H

#include <cmath>
#include <bitset>
#include "Address.h"

class Range {
public:
    // can be called statically
    bool isValid();

    Range() // pretty useless
    {
        setAddress(new Address);
        setMask(0);
    }

    Range(std::string str) // this one will be called most
    {
        std::istringstream istr;
        istr.str(str);

        // used to pass in the address and mask
        std::string tempStr;
        int tempMsk;

        getline(istr, tempStr, '/');
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