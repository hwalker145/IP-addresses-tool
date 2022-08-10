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
void aggregateRanges(Book* b) {
	#ifdef _UNICODE
		constexpr _TCHAR* _TSUBNET = L"Subnet";
		constexpr _TCHAR* _V6HEADER = L"IPV6 Ranges";
		constexpr _TCHAR* _V4HEADER = L"IPV4 Ranges";
		constexpr _TCHAR* _SHEET = L"Aggregated Addresses";
	#else 
		constexpr _TCHAR* _TSUBNET = "Subnet";
		constexpr _TCHAR* _V6HEADER = "IPV6 Ranges";
		constexpr _TCHAR* _V4HEADER = "IPV4 Ranges";
		constexpr _TCHAR* _SHEET = "Aggregated Addresses";
	#endif


	Sheet* sh;
	int subnetCol = -1;
	int sheets = b->sheetCount();
	int i = 0;

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
						ranVec6.push_back(ran);
					}
					else if (ran->getAddress()->getVersion() == 4) {
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

		for (i = 0; i < ranVec4.size() - 1; i++) {
			if (ranVec4[i]->canMerge(ranVec4[i + 1])) {

				ranVec4.erase(ranVec4.begin() + i + 1);
				ranVec4[i]->setMask(ranVec4[i]->getMask() - 1);
				contLoop = true;
			}
		}		
	}

	contLoop = true;

	while (contLoop) {
		contLoop = false;

		for (i = 0; i < ranVec4.size() - 1; i++) {
			if (ranVec4[i]->canMerge(ranVec4[i + 1])) {

				ranVec4.erase(ranVec4.begin() + i + 1);
				ranVec4[i]->setMask(ranVec4[i]->getMask() - 1);
				contLoop = true;
			}
		}
	}

	Book* n = xlCreateXMLBook();
	sh = n->addSheet(_SHEET);

	sh->writeStr(0, 0, _V4HEADER);
	sh->writeStr(0, 1, _V6HEADER);

	for (i = 0; i < ranVec4.size(); i++) {
		sh->writeStr(i + 1, 0, ranVec4[i]->asString());
	}

	for (i = 0; i < ranVec6.size(); i++) {
		sh->writeStr(i + 1, 0, ranVec6[i]->asString());
	}

	return;
}
