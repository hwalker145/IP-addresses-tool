# IP-addresses-tool --

is a project that I wanted to do in C++ so to explore the ways I can use other people's code to make my own project work. For this I am using the libxl framework to read and write MS excel with C++. https://www.libxl.com/home.html

Some more details: the program is designed for a command-line use case. Two functions make up this program. First, the search function. The program searches for an IP address range in which an address fits. This takes as input an xlsx ffile with a column header 'Subnet' containing IP ranges below, and an IP address input both through the command line. The program will return in the command line a report of the IP range in which the address fits.
The other function is called aggregate. The program takes as input an xlsx file and outputs a new xlsx file with the IP ranges aggregated.
