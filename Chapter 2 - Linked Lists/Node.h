#include <iostream>

namespace unsafe {
struct Node {
    Node * next = nullptr;
    int data;
    Node(int d) : data{d} {}
    void appendToTail(int d) 
    {
        auto n = this;
        while (n->next != nullptr) n = n->next;
        n->next = new Node{d};
    }
};

Node* deleteNode(Node* head, int d)
{
    if (!head) return nullptr;

    auto n = head;

    while (n->next)
    {
        if (n->next->data == d)
        {
            auto nodeToDelete = n->next;
            n->next = n->next->next;
            delete nodeToDelete;
        }
        else
        {
            n = n->next;
        }
    }

    if (head->data == d)
    {
        auto result = head->next;
        delete head;
        return result;
    }

    return head;
}

void printList(const Node* head)
{
    while (head)
    {
        std::cout << head->data << "\t->\t";
        head = head->next;
    }

    std::cout << "NULL" << std::endl;
}

}
