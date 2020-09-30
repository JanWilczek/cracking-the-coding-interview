#include <iostream>
#include <memory>

struct SafeNode
{
    std::unique_ptr<SafeNode> next{nullptr};
    int data;
    SafeNode(int d) : data{d} {};
    void appendToTail(int d)
    {
        auto n = this;
        while (n->next) n = n->next.get();
        n->next = std::make_unique<SafeNode>(d);
    }
};

std::unique_ptr<SafeNode> deleteSafeNode(std::unique_ptr<SafeNode> head, int d)
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

void printList(SafeNode* head)
{
    while (head)
    {
        std::cout << head->data << "\t->\t";
        head = head->next.get();
    }

    std::cout << "NULL" << std::endl;
}
