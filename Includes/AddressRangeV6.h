// AddressRangeV6.h
#ifndef ADDRESSRANGEV6_H
#define ADDRESSRANGEV6_H

#include <iostream> // to work with the console
#include <sstream>  // to work with the dots and numbers
#include <string>   // to work with sstream
#include <cmath>    // to use exponents
#include <iomanip>  // to bring an integer back to hex

#include "AddressV6.h"

using namespace std;

class AddressRangeV6 // our class to work with address ranges
{
public:
    AddressRangeV6(); // default constructor
    AddressRangeV6(string addString); // constructor using string

    void setString(string addString); // sets the whole range string
    void setMinAddress(AddressV6 *addPtr); // mutator for the minimum addy ptr
    void setMaxAddress(AddressV6 *addPtr); // mutator for the maximum addy ptr
    void setSubnetSize(int size); // mutator for the network size

    AddressV6 *getMaxAddress() const; // access max addy (returns ptr to object)
    AddressV6 *getMinAddress() const; // access min addy (returns ptr to object)
    int getSubnetSize() const; // access subnet size (returns int)
    string getString() const; // returns the string of the whole address range

    string findMaxAddress() const; // finds the max address 
                             // and sets it with a call  to setMaxAddress

    ~AddressRangeV6(); // destructor
private:
    int mSubnetSize; // integer describing subnet size in bits
    AddressV6 *mMaxAddress, // pointers to the high address and the
              *mMinAddress; // low address for V6
};

#endif