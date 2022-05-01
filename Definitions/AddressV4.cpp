// IPaddress.cpp
#include "../Includes/AddressV4.h"

// default constructor
AddressV4::AddressV4()
{
    setChunk(0, 0);
    setChunk(1, 0);
    setChunk(2, 0);
    setChunk(3, 0);
}

// constructor with a string to load into chunks with iss
AddressV4::AddressV4(string add)
{
    stringToChunks(add);
}

// constructor with 4 integers
AddressV4::AddressV4(int a, int b, int c, int d)
{
    setChunk(0, a);
    setChunk(1, b);
    setChunk(2, c);
    setChunk(3, d);
}

void AddressV4::stringToChunks(string add)
{
    istringstream istr; // initializes istr

    istr.str(add); // loads string into istr

    string temp; // temporary string for getline to use
    int ctr = 0; // counter int to change the chunk

    while(!istr.eof()) // validates istr as continuous
    {
        getline(istr, temp, '.'); // takes delimited input

        setChunk(ctr, stoi(temp)); // casts into integer
                        // and mutates the chunks

        ctr++; // increments counter
    }
}

// mutator using int
void AddressV4::setChunk(int index, int val)
{
    mChunks[index] = val;
}

// accessor returning integer, takes chunk index
int AddressV4::getChunk(int index) const
{
    return mChunks[index];
}

// returns the IP addy as a string using an ostringstream
string AddressV4::getString() const
{
    ostringstream ostr; // initializes ostr

    ostr << getChunk(0) << '.' // puts a period
         << getChunk(1) << '.' // between chunks
         << getChunk(2) << '.' // in ostr
         << getChunk(3);

    return ostr.str(); // returns string version of the whole address
}

// destructor, all chunks to 0
AddressV4::~AddressV4()
{
    stringToChunks("0.0.0.0");
}