#include "../Includes/Aggregate.h"

// above includes <vector> in this file

bool comparator(Range* a, Range* b) {
	int cmp = a->getAddress()->addCmp(b->getAddress());
	if (cmp < 1) { return false; }
	return true;
}

/**
 * Function is a major part of the program and aggregates all 
 * found IP ranges into one new xlsx file. Does not throw errors,
 * ignores them.
 * 
 * \param b -- book to search
 */
void aggregateRanges(Book* b) {
	#ifdef _UNICODE
		constexpr _TCHAR* _TSUBNET = L"Subnet";
	#else 
		constexpr _TCHAR* _TSUBNET = "Subnet";
	#endif

	Sheet* sh;
	int subnetCol = -1;

	std::vector<Range*> ranVec;

	for (int i = 0; i < b->sheetCount(); i++) {
		if (sh = b->getSheet(i)) {
			for (int j = sh->firstFilledCol(); j < sh->lastFilledCol(); j++) {
				if (sh->readStr(0, j) == _TSUBNET) {
					subnetCol = j;
				}
			}

			for (int j = sh->firstFilledRow() + 1; j < sh->lastFilledRow(); j++) {
				if (sh->cellType(j, subnetCol) == CELLTYPE_STRING) {
					ranVec.push_back(new Range(sh->readStr(j, subnetCol)));
				}
			}
		}
	}

	std::sort(ranVec.begin(), ranVec.end(), comparator);

	bool contLoop = true;

	while (contLoop) {
		contLoop = false;

		for (int i = 0; i < ranVec.size() - 1; i++) {
			if (ranVec[i] == nullptr) { continue; }
			if (ranVec[i]->canMerge(ranVec[i + 1])) {
				delete ranVec[i + 1];
				ranVec[i + 1] = nullptr;

				ranVec[i]->setMask(ranVec[i]->getMask() - 1);

				contLoop = true;
			}
		}

		for (int i = 0; i < ranVec.size(); i++) {
			if (ranVec[i] != nullptr) {
				std::cout << ranVec[i]->getAddress()->asString() << _TSLASH << ranVec[i]->getMask() << '\n';
			}
		}
	}
}
