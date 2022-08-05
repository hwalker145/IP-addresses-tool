#include "../Includes/IPAddress.h"
#include "libxl.h"

using namespace libxl;

int main(int argc, char** argv) {
		
	try {
		Book* B = xlCreateXMLBook();

		size_t ctr;

		if (B->load("xlsx\\IP Ranges Sample.xlsx")) {

			ctr = aggregateRanges(B);
			B->release();
		}
		return 0;
	}
	catch (std::logic_error le) {
		std::cout << le.what() << '\n';
		return 1;
	}
	catch (...) {
		return 2;
	}
}
