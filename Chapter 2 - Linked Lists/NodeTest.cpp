#include "Node.h"
#include "SafeNode.h"

void nodeTest()
{
    auto head = new Node{1};
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(4);
    head->appendToTail(5);
    printList(head);
    head = deleteNode(head, 1);
    head = deleteNode(head, 3);
    head = deleteNode(head, 5);
    head = deleteNode(head, 6);
    printList(head);

    while (head)
    {
        head = deleteNode(head, head->data);
    }
}

void safeNodeTest()
{
    auto head = std::make_shared<SafeNode>(1);
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(4);
    head->appendToTail(5);
    printList(head);
    head = deleteSafeNode(head, 1);
    head = deleteSafeNode(head, 3);
    head = deleteSafeNode(head, 5);
    head = deleteSafeNode(head, 6);
    printList(head);
}

int main()
{
    nodeTest();
    safeNodeTest();
}
