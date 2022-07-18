#include "../Includes/IPAddress.h"

using namespace libxl;

int main()
{
	try 
	{
		Book* B = xlCreateXMLBook();
		if (!B->load("../xlsx/IP Ranges Sample.xlsx"))
		{
			throw B->errorMessage();
		}
	}
	catch (char* exception)
	{
		exit(1);
	}
	catch (...)
	{
		exit(1);
	}
	return 0;
}
