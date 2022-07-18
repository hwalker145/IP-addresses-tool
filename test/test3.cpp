#include "../Includes/IPAddress.h"

using namespace libxl;

int main()
{
	try 
	{
		Book* B = xlCreateXMLBook();

	}
	catch (wchar_t * exception)
	{
		exit(1);
	}
	catch (...)
	{
		exit(1);
	}
	return 0;
}
