// AddressV6.h
#ifndef ADDRESSV6_H
#define ADDRESSV6_H

#include <iostream> // to work with the console
#include <sstream>  // to work with the dots and numbers
#include <string>   // to work with sstream
#include <iomanip>  // to bring an integer back to hex

using std::wistringstream;
using std::wostringstream;
using std::wstring;
using std::hex;
using std::wcout;
using std::getline;

class AddressV6 // our class to be an IP address
{
public:
    AddressV6(); // default constructor, all chunks 0
    AddressV6(wstring); // constructs with string, using istringstream

    void setString(wstring add); // sets the whole address from a string
    void setChunk(int chunkNum, wstring chunkValue); // sets single chunk
    void setChunk(int chunkNum, int chunkValue); // sets the chunk as int

    const int getChunkInteger(int chunkNum); // returns as an integer
    const wstring getChunkString(int chunkNum); // returns as a string
    const wstring getString(); // returns the string of the address

    ~AddressV6(); // destructor, all chunks to 0
private:
    wstring mChunksString[8];
};

#endif