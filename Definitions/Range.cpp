#include "../Includes/Range.h"

/**
 * @brief function finds mathematically if the address
 *      is compatible with the bitmask
 * 
 * @tparam accepts type of address
 * @param ran range to be evaluated
 * @return true if range is valid
 * @return false if not
 */
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
        // if the character hex val isn't all zeros from the most significant 
        // client bit down to the least in the character ... invalid
        return false;
    }

    // runs from the next least significant character to the mask in v6 
    // to the L.S.B. in the chunk
    for(int i = 4 - charIndex; i < 4; i++)
    {
        if(stoi(ran->getAddress()->getChunkString(7 - chunkIndex).substr(i, 1), nullptr, 16))
        {
            // if the second most significant client character (4 bits) down to
            // the least in the chunk have any nonzero characters ... invalid
            return false;
        }
    }

    // runs from the chunk next least significant to the masking chunk
    // to the least significant chunk
    for(int j = chunkIndex; j > 0; j--)
    {
        if(ran->getAddress()->getChunkString(8 - chunkIndex) == "")
        {
            // we ignore it if it's empty ... though not necessary given
            // we don't have empty chunks right now
            continue;
        }
        if(stoi(ran->getAddress()->getChunkString(8 - chunkIndex), nullptr, 16))
        {
            // if any nonzero client chunks aside from the boundary chunk
            // ... invalid
            return false;
        }
    }
    return true;
}

/**
 * @brief finds out if the mask and the address are compatible...
 *      much less difficult for V4
 * 
 * @tparam accepts type of address
 * @param ran address range
 * @return true if valid
 * @return false if not
 */
template<>
bool Range<AddressV4>::isValid(Range* ran)
{
    // 8 bits per chunk
    // mask is 0 - 32
    int chunkIndex = ran->getMask() / 8;

    // if the boundary chunk has any bits nonzero within the client section ... invalid
    if(ran->getAddress()->getChunk(3 - chunkIndex) % (int)pow(2, ran->getMask() % 4))
    {
        return false;
    }

    for(int i = chunkIndex; i > 0; i--)
    {
        // if any chunks less significant are nonzero ... invalid
        if(ran->getAddress()->getChunk(4 - i))
        {
            return false;
        }
    }
    return true;
}

