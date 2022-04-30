// AddressRangeV4.h
#ifndef ADDRESSRANGEV4_H
#define ADDRESSRANGEV4_H

#include <iostream> // to work with the console
#include <sstream>  // to work with the dots and numbers
#include <string>   // to work with sstream
#include <cmath>    // to use exponents

#include "AddressV4.h"

using namespace std;

class AddressRangeV4 // our class to work with address ranges
{
public:
    AddressRangeV4(); // default constructor
    AddressRangeV4(string addRange); // constructor using string

    void setString(string addString); // sets the whole range string
    void setMaxAddress(AddressV4 *addPtr); // mutator for max addy. passes object
    void setMinAddress(AddressV4 *addPtr); // mutator for min addy. passes object
    void setSubnetSize(int size); // mutator for subnet size passes integer

    AddressV4 *getMaxAddress() const; // access max addy (returns ptr to object)
    AddressV4 *getMinAddress() const; // access min addy (returns ptr to object)
    int getSubnetSize() const; // access subnet size (returns int)
    string getString() const; // returns the string of the whole address range
    
    string findMaxAddress() const; // finds the max address and sets it with a call
                        // to setMaxAddress

    ~AddressRangeV4(); // destructor
private:
    int mSubnetSize;
    AddressV4 *mMaxAddress, // the high address and the
              *mMinAddress; // low address for V6
};

#endif