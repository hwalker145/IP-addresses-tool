#ifndef RANGE_H
#define RANGE_H

#include <cmath>
#include "AddressV4.h"
#include "AddressV6.h"

template <typename T>
class Range {
public:
    // can be called statically
    static bool isValid(Range*);

    Range() // pretty useless
    {
        setAddress(new T);
        setMask(0);
    }

    Range(string str) // this one will be called most
    {
        istringstream istr;
        istr.str(str);

        // used to pass in the address and mask
        string tempStr;
        int tempMsk;

        getline(istr, tempStr, '/');
        istr >> tempMsk;

        setAddress(new T(tempStr));
        setMask(tempMsk);
    }

    Range(T* ptr, int msk) // this one will be used indirectly
    {
        setAddress(ptr);
        setMask(msk);
    }

    T* findMax();

    void setAddress(T* add) {address = add;};
    // a wrapper to use on the generated address from Range::findMax
    // not 100p necessary I guess

    void setMaxAddress(T* add) {maxAddress = add;};
    T* getAddress() const {return address;};
    T* getMaxAddress() const {return maxAddress;};

    void setMask(int msk) {mask = msk;};
    int getMask() const {return mask;};

    ~Range()
    {
        delete address;
        delete maxAddress;

        address = maxAddress = nullptr;
    }

private:
    int mask;
    T* address, maxAddress;
};

#endif