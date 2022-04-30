#include "../Includes/AddressRangeV6.h"

AddressRangeV6::AddressRangeV6()
{
    setString("0:0:0:0:0:0:0:0/0");
}

AddressRangeV6::AddressRangeV6(string addString)
{
    setString(addString);
}

void AddressRangeV6::setString(string addString)
{
    istringstream istr;
    istr.str(addString);

    string temp;    // temporary string for getline return
    int subnetSize; // temporary integer for subnetSize

    getline(istr, temp, '/'); // gets min address into temp
    istr >> subnetSize;       // sends the network size into subnetSize

    setSubnetSize(subnetSize); // changes the subnetsize using fnct

    mMinAddress = new AddressV6(temp); 
    mMaxAddress = new AddressV6(findMaxAddress());
}

void AddressRangeV6::setMinAddress(AddressV6 *addPtr)
{
    delete mMinAddress;
    mMinAddress = addPtr;
}

void AddressRangeV6::setMaxAddress(AddressV6 *addPtr)
{
    delete mMaxAddress;
    mMaxAddress = addPtr;
}

void AddressRangeV6::setSubnetSize(int size)
{
    mSubnetSize = size;
}

AddressV6 *AddressRangeV6::getMinAddress() const
{
    return mMinAddress;
}

AddressV6 *AddressRangeV6::getMaxAddress() const
{
    return mMaxAddress;
}

int AddressRangeV6::getSubnetSize() const
{
    return mSubnetSize;
}

string AddressRangeV6::getString() const
{
    ostringstream ostr; // initialize ostringstream
    ostr << getMinAddress()->getString()
         << '/' << getSubnetSize();
    // sends the min and the slash and teh net size into ostr

    // ostr constructs a string here and returns
    return ostr.str();
}

// finds the max addy of the range
string AddressRangeV6::findMaxAddress() const
{
    int temp[8]; // creates temporary dummy of AddressV6::mChunks
    for(int ch = 0; ch < 8; ch++)
    {   // copied off of min addy
        temp[ch] = getMinAddress()->getChunkInteger(ch);
    }

    // the chunk we need to change is identified
    int chunkCalc = getSubnetSize() / 16;

    // then we add an exponent of 2
    temp[chunkCalc] += pow(2, 16 - (getSubnetSize() % 16));
    // and take away one
    temp[chunkCalc] -= 1;

    // the next chunks are 255
    for(int ch = chunkCalc + 1; ch < 8; ch++)
    {
        temp[ch] = 65535;
    }

    // construct an IP addy and return it as a string
    // using the ostringstream
    ostringstream ostr;
    ostr << hex
         << temp[0] << ':'
         << temp[1] << ':'
         << temp[2] << ':'
         << temp[3] << ':'
         << temp[4] << ':'
         << temp[5] << ':'
         << temp[6] << ':'
         << temp[7];

    return ostr.str();
}

AddressRangeV6::~AddressRangeV6()
{
    // destroys evidence
    delete mMinAddress;
    delete mMaxAddress;
}