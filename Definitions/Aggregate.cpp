#include "../Includes/Aggregate.h"

// above includes <vector> in this file

bool comparator(Range* a, Range* b) {
	int cmp = a->getAddress()->addCmp(b->getAddress());
	if (cmp > -1) { return false; }
	return true;
}

/**
 * Function is a major part of the program and aggregates all 
 * found IP ranges into one new xlsx file. Does not throw errors,
 * ignores them.
 * 
 * \param b -- book to search
 */
size_t aggregateRanges(Book* b) {
	#ifdef _UNICODE
		constexpr _TCHAR* _TSUBNET = L"Subnet";
	#else 
		constexpr _TCHAR* _TSUBNET = "Subnet";
	#endif


	Sheet* sh;
	int subnetCol = -1;
	int sheets = b->sheetCount();
	int i = 0;
	size_t ctr = 0;

	std::vector<Range*> ranVec6;
	std::vector<Range*> ranVec4;

	// reads in the ranges
	for (i = 0; i < b->sheetCount(); i++) {
		if (sh = b->getSheet(i)) {
			for (int j = sh->firstFilledCol(); j < sh->lastFilledCol(); j++) {
				if (!strcmp(sh->readStr(0, j), _TSUBNET)) {
					subnetCol = j;
				}
			}

			for (int j = sh->firstFilledRow() + 1; j < sh->lastFilledRow(); j++) {
				if (sh->cellType(j, subnetCol) == CELLTYPE_STRING) {
					Range * ran = new Range(sh->readStr(j, subnetCol));
					if (!ran->isValid()) { continue; }

					if (ran->getAddress()->getVersion() == 6) {
						ctr += (1 << (128 - ran->getMask()));
						ranVec6.push_back(ran);
					}
					else if (ran->getAddress()->getVersion() == 4) {
						ctr += (1 << (32 - ran->getMask()));
						ranVec4.push_back(ran);
					}
					else {
						throw std::runtime_error("Invalid IP version in aggregateRange");
					}
				}
			}
		}
	}

	std::sort(ranVec4.begin(), ranVec4.end(), comparator);
	std::sort(ranVec6.begin(), ranVec6.end(), comparator);

	bool contLoop = true;

	while (contLoop) {
		contLoop = false;

		//ctr = 0;
		std::cout << "----------------------------------\n";
		for (i = 0; i < ranVec4.size(); i++) {
		    std::cout << ranVec4[i]->asString() << '\n';
			//ctr += (1 << (32 - ranVec4[i]->getMask()));
		}

		//std::cout << ctr << '\n';

		for (i = 0; i < ranVec4.size() - 1; i++) {
			if (ranVec4[i]->canMerge(ranVec4[i + 1])) {
				std::cout << "Range: " << ranVec4[i]->asString() << " merges with Range: "
						  << ranVec4[i + 1]->asString() << '\n';

				ranVec4.erase(ranVec4.begin() + i + 1);
				ranVec4[i]->setMask(ranVec4[i]->getMask() - 1);
				contLoop = true;
			}
		}		
	}
	return ctr;
}
