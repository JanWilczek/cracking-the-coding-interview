#include <iostream>
#include <memory>

struct SafeNode
{
    std::shared_ptr<SafeNode> next{nullptr};
    int data;
    SafeNode(int d) : data{d} {};
    void appendToTail(int d)
    {
        auto n = this;
        while (n->next) n = n->next.get();
        n->next = std::make_shared<SafeNode>(d);
    }
};

std::shared_ptr<SafeNode> deleteSafeNode(std::shared_ptr<SafeNode> head, int d)
{
	if (!head) return nullptr;

	auto n = head;
	while (n->next)
	{
		if (n->next->data == d)
			n->next = n->next->next;
		else
			n = n->next;
	}
	
	if (head->data == d)
		return head->next;
	return head;
}

void printList(std::shared_ptr<SafeNode> head)
{
    while (head)
    {
        std::cout << head->data << "\t->\t";
        head = head->next;
    }

    std::cout << "NULL" << std::endl;
}
