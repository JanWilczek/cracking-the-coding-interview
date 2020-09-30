#include "SafeNode.h"
#include <exception>
#include <assert.h>


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

int nthToLastWithSeeker(Node* head, int n)
{
	if (!head) throw std::invalid_argument{"Given list is empty."};

	// Assume at least n elements in the list
	auto seeker = head;
	while (n--)
	{
		seeker = seeker->next.get();
	}

	auto nthToSeeker = head;

	while (seeker->next)
	{
		seeker = seeker->next.get();
		nthToSeeker = nthToSeeker->next.get();
	}
	
	return nthToSeeker->data;
}

Node* nthToLastRecurseHelper(Node* head, int& n)
{
	if (!head->next)
	{
		return nullptr;
	}
	Node* result = nthToLastRecurseHelper(head->next.get(), n);
	if (!n--)
	{
		return head->next.get();
	}
	return result;
}

int nthToLastRecurse(Node* head, int n)
{
	Node* result = nthToLastRecurseHelper(head, n);
	return result->data;
}



int main()
{
    auto head = getTestList();
    printList(head.get());
    for (int n = 0; n < 8; ++n)
    {
        std::cout << n << std::skipws << "th element to last:\t" << nthToLast(head.get(), n) << std::endl;
        assert(nthToLast(head.get(), n) == nthToLastWithSeeker(head.get(), n));
        assert(nthToLast(head.get(), n) == nthToLastRecurse(head.get(), n));
    }
}
