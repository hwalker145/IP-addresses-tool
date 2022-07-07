// AddressV4.h
#ifndef ADDRESSV4_H
#define ADDRESSV4_H

#include <iostream> // to work with the console
#include <sstream>  // to work with the dots and numbers
#include <string>   // to work with sstream

using std::wistringstream;
using std::wostringstream;
using std::wstring;
using std::wcout;

class AddressV4 // our class to be an IP address
{
public:
    AddressV4(); // default constructor
    AddressV4(wstring add); // constructor with string
    AddressV4(int a, int b, int c, int d); // constructor
             // with int specifying the chunks

    void stringToChunks(wstring add); // sets the whole address taking a string
    void setChunk(int chunkNum, int chunkValue); // sets a specific
                                                 // chunk using an int

    int getChunk(int chunkNum) const; // chunk accessor as int
    wstring getString() const; // returns the string of the full address

    ~AddressV4(); // destructor
private:
    int mChunks[4];
};

#endif