#include "Node.h"

int main()
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
