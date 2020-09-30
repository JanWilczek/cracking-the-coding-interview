#include "SafeNode.h"
#include <unordered_set>

using namespace safe;

std::unique_ptr<Node> removeDuplicates(std::unique_ptr<Node> head)
{
	if (!head) return nullptr;

	std::unordered_set<int> values{head->data};

	Node* prev = head.get();
	Node* cur = head->next.get();

	while (cur)
	{
		if (values.find(cur->data) != values.end()) // contains() only in C++ 20
		{
			prev->next = std::move(cur->next);
			cur = prev->next.get();
		}
		else
		{
			values.insert(cur->data);
			prev = cur;
			cur = cur->next.get();
		}
	}

	return head;
}

std::unique_ptr<Node> removeDuplicatesNoBuffer(std::unique_ptr<Node> head)
{
    if (!head) return nullptr;
	Node* n = head.get();

	while (n->next)
	{
		auto prev = n;
		while (prev->next)
		{
			if (prev->next->data == n->data)
			{
				prev->next = std::move(prev->next->next);
			}
			else
            {
                prev = prev->next.get();
            }
		}

		if (n->next) n = n->next.get();
	}

	return head;
}

int main()
{
    auto head = getTestList();
    head->appendToTail(8);
    printList(head.get());
    head = removeDuplicates(std::move(head));
    printList(head.get());

    head = getTestList();
    head->appendToTail(8);
    head = removeDuplicatesNoBuffer(std::move(head));
    printList(head.get());
}

