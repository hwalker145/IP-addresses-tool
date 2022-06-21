#include "../Includes/IPAddress.h"

#include <iostream> // to work with the console
#include <sstream>  // to work with the dots and numbers
#include <string>   // to work with sstream
#include <iomanip>  // to use hex strings and integers

using std::istringstream;
using std::string;
using std::stoi;
using std::hex;

// default constructor
AddressV6::AddressV6()
{
    for(int i = 0; i < 8; i++)
    {
        setChunk(i, "");
    }
}

// constructs with string, uses getline and istringstream
AddressV6::AddressV6(string add)
{
    setString(add);
}

void AddressV6::setString(string str)
{
    istringstream istr; // initialize istr

    istr.str(str); // loads string into istr

    string temp; // temporary string to use std::getline

    string zero("0");

    int len;

    // i = 0, ... ,6
    for(int i = 0; i < 7; i++)
    {
        getline(istr, temp, ':');
        len = temp.length();
        
        for(int j = 0; j < 4 - len; j++)
        {
            temp = '0' + temp;
        }

        setChunk(i, temp);
    }
    istr >> temp;

    len = temp.length();
    for(int k = 0; k < 4 - len; k++)
    {
        temp = '0' + temp;
    }

    setChunk(7, temp);
}

// mutator using a string, 
// my setters/getters are not inline cause they're too long
void AddressV6::setChunk(int chunkNum, string chunkValue)
{
    mChunksString[chunkNum] = chunkValue; // standard mutator
}

// mutator using an integer, with ostringstream and iomanip
void AddressV6::setChunk(int chunkNum, int chunkValue)
{
    ostringstream ostr; // initialize ostr
    ostr << hex << chunkValue; // adds a hex of chunkValue to ostr
    mChunksString[chunkNum] = ostr.str(); // changes the chunk
}

// as string accessor
const string AddressV6::getChunkString(int chunkNum)
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
const string AddressV6::getString() 
{
    ostringstream ostr; // initializes ostr

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
        setChunk(i, "");
    }
}