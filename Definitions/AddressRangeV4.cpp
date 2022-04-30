#include "../Includes/AddressRangeV4.h"

// default constructor, min and max addy's to empty string
// and the subnet mask is 0 here
AddressRangeV4::AddressRangeV4()
{
    cout << "default range constructor called\n";
    setSubnetSize(0);

    mMinAddress = new AddressV4("0.0.0.0");
    mMaxAddress = new AddressV4("0.0.0.0");
}

// full member constructor, will call mutators
AddressRangeV4::AddressRangeV4(string addRange)
{
    setString(addRange);
}

// mutator for the whole shabang
void AddressRangeV4::setString(string addString)
{
    istringstream istr;   // initialize istringstream
    istr.str(addString);  // loads the string into istr

    string temp;    // temporary string for getline return
    int subnetSize; // temporary integer for subnetSize

    getline(istr, temp, '/'); // gets min address into temp
    istr >> subnetSize;       // sends the network size into subnetSize

    setSubnetSize(subnetSize); // changes the subnetsize using fnct

    mMinAddress = new AddressV4(temp); 
        // makes dynamic addressV4 for the min address
    mMaxAddress = new AddressV4(findMaxAddress());
        // makes dynamic addressV4 for max address, calling the max
        // address calculator function
}

// mutator for the min, takes addressv4 pointer
void AddressRangeV4::setMinAddress(AddressV4 *addPtr)
{
    delete mMinAddress; // kills the old min
    mMinAddress = addPtr; // points mMin to new location
}

// mutator for the max, takes addressv4 pointer
void AddressRangeV4::setMaxAddress(AddressV4 *addPtr)
{
    delete mMaxAddress; // kills the old max
    mMaxAddress = addPtr; // points mMax to the new place
}

// mutator for the subnet size, takes int
void AddressRangeV4::setSubnetSize(int size)
{
    mSubnetSize = size;
}

// accessor for the min, returns pointer to addv4
AddressV4 *AddressRangeV4::getMinAddress() const 
{
    return mMinAddress;
}

// accessor for the max, returns pointer to addv4
AddressV4 *AddressRangeV4::getMaxAddress() const
{
    return mMaxAddress;
}

// accessor for the subnet size, returns int
int AddressRangeV4::getSubnetSize() const
{
    return mSubnetSize;
}

// turns it into a string and returns
string AddressRangeV4::getString() const
{
    ostringstream ostr; // initialize ostringstream
    ostr << getMinAddress()->getString()
         << '/' << getSubnetSize();
    // sends the min and the slash and teh net size into ostr

    // ostr constructs a string here and returns
    return ostr.str();
}

// finds if an address fits this range

// finds the max addy of the range
string AddressRangeV4::findMaxAddress() const
{
    int temp[4]; // creates temporary dummy of AddressV4::mChunks
    for(int ch = 0; ch < 4; ch++)
    {   // copied off of min addy
        temp[ch] = getMinAddress()->getChunk(ch);
    }

    // the chunk we need to change is identified
    int chunkCalc = getSubnetSize() / 8;

    // then we add an exponent of 2
    temp[chunkCalc] += pow(2, 8 - (getSubnetSize() % 8));
    // and take away one
    temp[chunkCalc] -= 1;

    // the next chunks are 255
    for(int ch = chunkCalc + 1; ch < 4; ch++)
    {
        temp[ch] = 255;
    }

    // construct an IP addy and return it as a string
    // using the ostringstream
    ostringstream ostr;
    ostr << temp[0] << '.'
         << temp[1] << '.'
         << temp[2] << '.'
         << temp[3];

    return ostr.str();
}

AddressRangeV4::~AddressRangeV4()
{
    // destroys evidence
    delete mMinAddress;
    delete mMaxAddress;
}

