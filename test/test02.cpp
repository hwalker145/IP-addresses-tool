#include "../Includes/IPAddress.h"

using std::cout;
using namespace libxl;

int main(int argc, wchar_t **argv)
{
	try
	{
		Book* bk = xlCreateXMLBook();

		wstring ws(argv[1]);

		if (!bk->load(ws.c_str()))
		{
			cout << bk->errorMessage() << '\n';
			throw std::invalid_argument("Book failed to load. Exiting!");
		}

		int bksize = bk->sheetCount();
		
		if (!bksize)
		{
			throw std::invalid_argument("Empty book.");
		}

		Sheet* sh = bk->getSheet(0);

		if (sh == NULL)
		{
			throw std::runtime_error(bk->errorMessage());
		}

		int addCol = -1;
		for (int i = sh->firstFilledCol(); i < sh->lastFilledCol(); i++)
		{
			if (sh->readStr(0, i) == L"Subnet")
			{
				addCol = i;
				break;
			}
		}

		if (addCol == -1)
		{
			throw std::runtime_error("No Subnet column was found. Exiting.");
		}

		Range* ran = new Range(sh->readStr(1, addCol));

		if (ran->isValid())
		{
			wcout << ran->getAddress()->asString() << '\n';
		}
		else
		{
			throw std::runtime_error("Invalid IP range.");
		}
	}
	catch (const std::invalid_argument& ia)
	{
		cout << ia.what() << '\n';
		exit(1);
	}
	catch (const std::runtime_error& re)
	{
		cout << re.what() << '\n';
		exit(2);
	}
}
