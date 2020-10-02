#include "SafeNode.h"

using namespace safe;

std::unique_ptr<Node> sumListNumbers(const Node* l1, const Node* l2)
{
	int carry = 0;
	
	std::unique_ptr<Node> guard = std::make_unique<Node>(0);
	Node* current = guard.get();

	while (l1 || l2 || carry)
	{
		int instantSum = carry;
		if (l1) 
        {
            instantSum += l1->data;
            l1 = l1->next.get();
        }
        if (l2)
        {
            instantSum += l2->data;
            l2 = l2->next.get();
        }
		int digit = instantSum % 10;
		carry = instantSum / 10;

		current->appendToTail(digit);
		current = current->next.get();
	}	
	
	return std::move(guard->next);
}


int main()
{
    auto l1 = std::make_unique<Node>(3);
    l1->appendToTail(1);
    l1->appendToTail(5);
    
    auto l2 = std::make_unique<Node>(5);
    l2->appendToTail(9);
    l2->appendToTail(2);

    printList(l1.get());
    printList(l2.get());

    auto result = sumListNumbers(l1.get(), l2.get());
    printList(result.get());
}
