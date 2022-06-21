#include "../Includes/Range.h"

// might not want to call this one
template<typename T>
Range<T>::Range()
{
    setAddress(new T);
    setMask(0);
}

template<typename T>
Range<T>::Range(string str)
{
    istringstream istr;
    istr.str(str);

    // used to pass in the address and mask
    string tempStr;
    int tempMsk;

    getline(istr, tempStr, '/');
    istr >> tempMsk;

    Range<T>(new T(tempStr), tempMsk);
}

template<typename T>
Range<T>::Range(T* ptr, int msk)
{
    setAddress(ptr);
    setMask(msk);

    findMax();
}

template<>
bool Range<AddressV6>::isValid(AddressV6* ptr, int msk)
{
    // sixteen bits per chunk
    // msk (from 0 - 127)
    // chunk index = msk / 16 (from 0 - 7)
    int chunkIndex = msk / 16;
    // most significant host bit in chunk = msk % 16 - 1 (from 0 - 15)
    int bitInChunkIndex = msk % 16 - 1;
    // mask character index in the chunk (from 0 - 3)
    int charIndex = bitInChunkIndex / 4;

    // checks if the mask boundary character is correct
    // we start with the character needed
    int charValue = stoi(ptr->getChunkString(chunkIndex).substr(3 - charIndex, 1), nullptr, 16);
    if((charValue % (int)pow(2, (bitInChunkIndex % 4 + 1))))
    { 
        return false;
    }

    // runs from the next least significant character to the mask in v6 
    // to the L.S.B. in the chunk
    for(int i = (4 - charIndex); i < 4; i--)
    {
        if(stoi(ptr->getChunkString(chunkIndex).substr(i, 1)), nullptr, 16)
        {
            return false;
        }
    }

    // runs from the chunk next least significant to the masking chunk
    // to the least significant chunk
    for(int j = chunkIndex; j > 0; j--)
    {
        if(ptr->getChunkString(chunkIndex) == "")
        {
            continue;
        }
        if(stoi(ptr->getChunkString(chunkIndex), nullptr, 16))
        {
            return false;
        }
    }
    return true;
}
