#include "Node.h"
#include "SafeNode.h"

void nodeTest()
{
    using namespace unsafe;

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
    using namespace safe;

    auto head = getTestList();
    printList(head.get());
    head = deleteNode(std::move(head), 1);
    head = deleteNode(std::move(head), 3);
    head = deleteNode(std::move(head), 5);
    head = deleteNode(std::move(head), 6);
    printList(head.get());
}

int main()
{
    nodeTest();
    safeNodeTest();
}
