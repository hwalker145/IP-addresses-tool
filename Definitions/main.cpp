#include "../Includes/IPAddress.h"
#include "libxl.h"

using namespace libxl;

int main(int argc, char** argv) {
	try {
		int* flags = new int[argc - 1];
		for (int i = 1; i < argc; i++) {
			if (argv[i][0] == '-') {
				flags[i] = 1;
			}
			else { flags[i] = 0; }
		}
		
		return 0;
	}
	catch (...) {
		return 1;
	}
}
