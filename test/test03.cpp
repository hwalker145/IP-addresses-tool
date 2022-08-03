#include "../Includes/IPAddress.h"

using namespace libxl;

int main() {
	try {
		Book* B = xlCreateXMLBook();
		if (!B->load("C:\\Users\\walkerh4\\source\\repos\\hwalker145\\IP-addresses-tool\\xlsx\\IP Ranges Sample.xlsx")) {
			throw B->errorMessage();
		}

		Sheet* sh = B->getSheet(0);

		if (!sh) {
			throw B->errorMessage();
		}

		int addressCol = -1;

		for (int i = sh->firstFilledCol(); i < sh->lastFilledCol(); i++) {
			if (!strcmp("Subnet", sh->readStr(0, i))) {
				addressCol = i;
			}
		}

		if (addressCol == -1) {
			throw std::runtime_error("No column contains as header \"Subnet\".");
		}

		Range* ran;

		for (int i = 1; i < sh->lastFilledRow(); i++)
		{
			ran = new Range(sh->readStr(i, addressCol));
			std::cout << "Address: " << ran->getAddress()->asString() << " Valid range? " << ran->isValid() << '\n';
		}
	}
	catch (const char* exception) {
		std::cout << exception << '\n';
		exit(3);
	}
	catch (...) {
		exit(2);
	}
	return 0;
}
