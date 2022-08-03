#include "../Includes/IPAddress.h"

int main() {
	std::srand(std::time(0));
	std::vector<Range*> ranVec;

	for (int i = 0; i < 10; i++)
	{
		ranVec.push_back(new Range("0.0.0.0/20"));
		ranVec.back()->getAddress()->setChunk((size_t)(std::rand() % 256), 3);
	}

	std::sort(ranVec.begin(), ranVec.end(), comparator);

	for (int i = 0; i < 10; i++)
	{
		std::cout << ranVec.back()->getAddress()->asString() << '\n';
		ranVec.pop_back();
	}

	return 0;
}
