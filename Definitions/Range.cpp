#include "../Includes/Range.h"

template<>
bool Range<AddressV6>::isValid(Range* ran)
{
    // sixteen bits per chunk
    // msk (from 0 - 127)
    // chunk index = msk / 16 (from 0 - 7)
    int chunkIndex = ran->getMask() / 16;
    // mask character index in the chunk (from 0 - 3)
    int charIndex = (ran->getMask() % 16) / 4;

    // checks if the mask boundary character is correct
    // we start with the character needed

    int charValue = stoi(ran->getAddress()->getChunkString(7 - chunkIndex).substr(3 - charIndex, 1), nullptr, 16);
    
    if(charValue % (int)pow(2, (ran->getMask() % 4)))
    {  
        return false;
    }

    // runs from the next least significant character to the mask in v6 
    // to the L.S.B. in the chunk
    for(int i = 4 - charIndex; i < 4; i++)
    {
        if(stoi(ran->getAddress()->getChunkString(7 - chunkIndex).substr(i, 1), nullptr, 16))
        {
            return false;
        }
    }

    // runs from the chunk next least significant to the masking chunk
    // to the least significant chunk
    for(int j = chunkIndex; j > 0; j--)
    {
        if(ran->getAddress()->getChunkString(8 - chunkIndex) == "")
        {
            continue;
        }
        if(stoi(ran->getAddress()->getChunkString(8 - chunkIndex), nullptr, 16))
        {
            return false;
        }
    }
    return true;
}
