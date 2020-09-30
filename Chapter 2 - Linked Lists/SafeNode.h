#include <iostream>
#include <memory>

namespace safe {
struct Node
{
    std::unique_ptr<Node> next{nullptr};
    int data;
    Node(int d) : data{d} {};
    void appendToTail(int d)
    {
        auto n = this;
        while (n->next) n = n->next.get();
        n->next = std::make_unique<Node>(d);
    }
};

std::unique_ptr<Node> deleteNode(std::unique_ptr<Node> head, int d)
{
	if (!head) return nullptr;

	auto n = head.get();
	while (n->next)
	{
		if (n->next->data == d)
			n->next = std::move(n->next->next);
		else
			n = n->next.get();
	}
	
	if (head->data == d)
		return std::move(head->next);
	return head;
}

void printList(const Node* head)
{
    while (head)
    {
        std::cout << head->data << "\t->\t";
        head = head->next.get();
    }

    std::cout << "NULL" << std::endl;
}

std::unique_ptr<Node> getTestList()
{
    auto head = std::make_unique<Node>(1);
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(2);
    head->appendToTail(5);
    head->appendToTail(1);
    head->appendToTail(1);
    head->appendToTail(8);
    return head;
}

}
