#include "../Includes/IPAddress.h"

int main() {
	Range*** ranArr = new Range ** [5];

	for (int i = 0; i < 5; i++) {
		ranArr[i] = new Range * [2];
	}

	ranArr[0][0] = new Range("0.0.0.1/32"); ranArr[0][1] = new Range("0.0.0.0/32");
	ranArr[1][0] = new Range("0.0.0.2/31"); ranArr[1][1] = new Range("0.0.0.0/31");
	ranArr[2][0] = new Range("0.0.12.0/22"); ranArr[2][1] = new Range("0.0.8.0/22");
	ranArr[3][0] = new Range("1.0.128.0/17"); ranArr[3][1] = new Range("1.0.0.0/17");
	ranArr[4][0] = new Range("64.0.0.1/3"); ranArr[4][1] = new Range("96.0.0.0/3");

	for (int i = 0; i < 5; i++) {
		if (ranArr[i][0]->canMerge(ranArr[i][1])) {
			std::cout << "Range " << i + 1 << " can merge!\n";
		}
	}

	return 0;
}