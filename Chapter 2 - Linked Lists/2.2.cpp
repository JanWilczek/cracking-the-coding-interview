#include "SafeNode.h"
#include <exception>


using namespace safe;

int nthToLast(Node* head, int n)
{
	if (!head) throw std::invalid_argument{"Given list is empty."};

	int elementCount = 0;

	auto cur = head;

	while (cur)
	{
		++elementCount;
		cur = cur->next.get();
	}

	const int maxElementToLastId = elementCount - 1;
	if (maxElementToLastId < n) throw std::out_of_range{"Not enough elements in the list."};

	int searchedElementId = maxElementToLastId - n;

	cur = head;
	while (searchedElementId--)
	{
		cur = cur->next.get();
	}

	return cur->data;
}

int main()
{
    auto head = getTestList();
    printList(head.get());
    for (int n = 0; n < 8; ++n)
    {
        std::cout << n << std::skipws << "th element to last:\t" << nthToLast(head.get(), n) << std::endl;
    }
}
