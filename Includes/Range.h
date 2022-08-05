#ifndef RANGE_H
#define RANGE_H

#include <cmath>
#include "Address.h"

class Range {
public:
    bool isValid();

    bool canMerge(Range*);

    Range() // pretty useless
    {
        setAddress(new Address("0.0.0.0"));
        setMaxAddress(nullptr);
        setMask(0);
    }

    Range(_TSTR str) // this one will be called most
    {
        _TISTR istr;
        istr.str(str);

        // used to pass in the address and mask
        _TSTR tempStr;
        int tempMsk;

        getline(istr, tempStr, _TSLASH);
        istr >> tempMsk;

        setAddress(new Address(tempStr));
        setMask(tempMsk);
    }

    Address* findMax();

    _TSTR asString() {
        _TOSTR ostr;
        ostr << getAddress()->asString() << '/' << getMask();
        return ostr.str();
    }

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