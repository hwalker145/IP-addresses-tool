// AddressV4.h
#ifndef ADDRESSV4_H
#define ADDRESSV4_H

#include <iostream> // to work with the console
#include <sstream>  // to work with the dots and numbers
#include <string>   // to work with sstream

using namespace std;

class AddressV4 // our class to be an IP address
{
public:
    AddressV4(); // default constructor
    AddressV4(string add); // constructor with string
    AddressV4(int a, int b, int c, int d); // constructor
        // with int specifying the chunks, probs won't use at all

    void setString(string add); // sets the whole address taking a string
    void setChunk(int chunkNum, int chunkValue); // sets a specific
                                                 // chunk using an int

    int getChunk(int chunkNum) const; // chunk accessor as int
    string getString() const; // returns the string of the full address

    ~AddressV4(); // destructor
private:
    int mChunks[4];
};

#endif