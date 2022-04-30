// AddressV6.h
#ifndef ADDRESSV6_H
#define ADDRESSV6_H

#include <iostream> // to work with the console
#include <sstream>  // to work with the dots and numbers
#include <string>   // to work with sstream
#include <iomanip>  // to bring an integer back to hex

using namespace std;

class AddressV6 // our class to be an IP address
{
public:
    AddressV6(); // default constructor, all chunks 0
    AddressV6(string add); // constructs with string, using istringstream

    void setString(string add); // sets the whole address from a string
    void setChunk(int chunkNum, string chunkValue); // sets single chunk
    void setChunk(int chunkNum, int chunkValue); // sets the chunk as int

    const int getChunkInteger(int chunkNum); // returns as an integer
    const string getChunkString(int chunkNum); // returns as a string
    const string getString(); // returns the string of the address

    ~AddressV6(); // destructor, all chunks to 0
private:
    string mChunksString[8];
};

#endif