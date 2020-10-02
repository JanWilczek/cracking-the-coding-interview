#include "SafeNode.h"

using namespace safe;

void deleteMiddleNode(Node* middleNode)
{
	if (!middleNode || !middleNode->next) return;

	middleNode->data = middleNode->next->data;
	middleNode->next = std::move(middleNode->next->next);
}


int main()
{
    auto head = std::make_unique<Node>(1);
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(4);
    head->appendToTail(5);
    printList(head.get());
    deleteMiddleNode(head->next->next.get());
    printList(head.get());
}
