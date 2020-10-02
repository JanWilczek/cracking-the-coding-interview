#include "Node.h"
#include <unordered_set>
#include <cassert>

using namespace unsafe;

Node* findLoop(Node* head)
{
	std::unordered_set<Node*> visited;
	
	Node*  current = head;
	while (current)
	{
		if (visited.find(current) != visited.end()) return current;
		visited.insert(current);
		// current = current->next.get(); // implementation chagned to unsafe for testing purposes
		current = current->next;
	}
	
	return nullptr;	// no loop found
}


int main()
{
    auto head = new Node{1};
    head->appendToTail(2);
    head->appendToTail(3);
    auto loopBegin = head->next->next;
    loopBegin->appendToTail(4);
    loopBegin->appendToTail(5);
    loopBegin->next->next->next = loopBegin;

    auto result = findLoop(head);
    assert(result == loopBegin);

    auto temp = head;
    for (int i = 0; i < 4; ++i)
    {
        auto nodeToDelete = temp;
        temp = temp->next;
        delete nodeToDelete;
    }
    delete temp;
}
