#include "../Includes/IPAddress.h"
#include "libxl.h"

using namespace libxl;

int main(int argc, char** argv) {
		
	try {
		Book* B = xlCreateXMLBook();

		if (B->load("xlsx\\IP Ranges Sample.xlsx")) {

			aggregateRanges(B);

			B->release();
		}
		return 0;
	}
	catch (std::logic_error le) {
		std::cout << le.what() << '\n';
		return 1;
	}
	catch (std::runtime_error re) {
		std::cout << re.what() << '\n';
		return 2;
	}
	catch (...) {
		return 3;
	}
}
