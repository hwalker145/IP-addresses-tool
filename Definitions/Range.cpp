#include "../Includes/Range.h"

using std::cerr;

template<typename T>
Range<T>::Range()
{
    setAddress(new T);
    setMask(0);
}

template<typename T>
Range<T>::Range(T* ptr, int msk)
{
    setAddress(ptr);
    setMask(msk);

    findMax();
}
