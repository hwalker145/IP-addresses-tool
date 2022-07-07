#include "../Includes/IPAddress.h"

#include <iostream> // to work with the console
#include <sstream>  // to work with the dots and numbers
#include <string>   // to work with sstream
#include <iomanip>  // to use hex strings and integers

using std::wistringstream;
using std::wstring;
using std::stoi;
using std::hex;

// default constructor
AddressV6::AddressV6()
{
    for(int i = 0; i < 8; i++)
    {
        setChunk(i, L"");
    }
}

// constructs with string, uses getline and istringstream
AddressV6::AddressV6(wstring add)
{
    setString(add);
}

void AddressV6::setString(wstring str)
{
    wistringstream istr; // initialize istr

    istr.str(str); // loads string into istr

    wstring temp; // temporary string to use std::getline

    wstring zero(L"0");

    int len;
    int i = 0;

    // i = 0, ... ,6
    while(!istr.eof())
    {
        getline(istr, temp, L':');
        len = (int)temp.length();
        
        for(int j = 0; j < 4 - len; j++)
        {
            temp = L'0' + temp;
        }

        setChunk(i++, temp);
    }
}

// mutator using a string, 
// my setters/getters are not inline cause they're too long
void AddressV6::setChunk(int chunkNum, wstring chunkValue)
{
    mChunksString[chunkNum] = chunkValue; // standard mutator
}

// mutator using an integer, with ostringstream and iomanip
void AddressV6::setChunk(int chunkNum, int chunkValue)
{
    wostringstream ostr; // initialize ostr
    ostr << hex << chunkValue; // adds a hex of chunkValue to ostr
    mChunksString[chunkNum] = ostr.str(); // changes the chunk
}

// as string accessor
const wstring AddressV6::getChunkString(int chunkNum)
{
    return mChunksString[chunkNum]; // standard accessor
}

// accessor, returns an integer
// returns huge number, don't use yet
const int AddressV6::getChunkInteger(int chunkNum)
{
    // stoi with base 16
    return stoi(mChunksString[chunkNum], nullptr, 16);
}

// returns the full address as a string, with ostringstream
const wstring AddressV6::getString() 
{
    wostringstream ostr; // initializes ostr

    for(int i = 0; i < 7; i++)
    { // from 0 to 6, we throw in the chunk then a ':'
        ostr << getChunkString(i) << ":";
    } // and then add the last chunk without a ':' at the end
    ostr << getChunkString(7);

    return ostr.str(); // return ostr as a string
}

// destructor
AddressV6::~AddressV6()
{ // not really sure what to put in here, but
    // all chunks become empty strings
    for(int i = 0; i < 8; i++)
    {
        setChunk(i, L"");
    }
}