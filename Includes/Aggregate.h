#include "Range.h"
#include "libxl.h"

#include <vector>
#include <algorithm>

using namespace libxl;

bool comparator(Range*, Range*);

void aggregateRanges(Book*);