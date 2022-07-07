#include "../Includes/IPAddress.h"
#include <stdexcept>

using namespace libxl;
using std::cout;

int main(int argc, char** argv) {
	try {
		// this program takes only two cli args
		if (argc != 2)
		{
			throw std::invalid_argument("Wrong number of CLI arguments. USAGE: <excel file>\nExiting.\n");
		}

		// the documented way to initialize a Book class
		Book* bk = xlCreateXMLBook();

		const wchar_t* pat = L"C:\\Users\\walkerh4\\Desktop\\Software\\VSCode\\IP-addresses-tool\\xlsx\\IP Ranges Sample.xlsx";

		// if this book can't load, throw
		if (!(bk->load(pat)))
		{
			throw std::invalid_argument("Invalid excel sheet\n");
		}

		// amount of sheets
		int booksize = bk->sheetCount();

		// if none, throw
		if (!booksize)
		{
			throw std::invalid_argument("Empty book\n");
		}

		// sh is the first sheet (at index zero) for the purposes of this test
		Sheet* sh = bk->getSheet(0);

		int subnetCol = -1;

		// traversing the column headings to find the subnet column
		for (int i = sh->firstFilledCol(); i < sh->lastFilledCol(); i++)
		{
			wstring heading = sh->readStr(0, i);

			if (heading == L"Subnet" || heading == L"subnet" || heading == L"SubNet")
			{
				subnetCol = i;
				break;
			}
		}

		if (subnetCol == -1)
		{
			throw std::runtime_error("No column had 'subnet' or 'Subnet' or 'SubNet' as header\n");
		}

		void* ptr = nullptr;

		wstring firstAdd = sh->readStr(1, subnetCol);
		for (int i = 1; i < 5; i++)
		{
			if (firstAdd[i] == L'.')
			{  
				reinterpret_cast<Range<AddressV4>*>(ptr);
				ptr = new Range<AddressV4>(firstAdd);
				break;
			}
			if (firstAdd[i] == L':')
			{			
				reinterpret_cast<Range<AddressV6>*>(ptr);
				ptr = new Range<AddressV6>(firstAdd);
				break;
			}
		}

		if(typeid(ptr).name() != "AddressV4" && typeid(ptr).name() != "AddressV6")
		{
			throw std::runtime_error("Address does not contain delimiter\n");
		}
		else
		{
			Range<AddressV4>* ran = new Range<AddressV4>(firstAdd);
			wcout << "Address at the top of the subnet column:\n"
				  << ran->getAddress()->getString() << '\n';
		}

		
	}

	catch (std::invalid_argument& ia)
	{
		cout << ia.what();
		exit(1);
	}
	
	catch (std::runtime_error re)
	{
		cout << re.what();
		exit(1);
	}

	return 0;
}