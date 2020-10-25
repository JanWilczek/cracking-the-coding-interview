#include <memory>
#include <cassert>
#include "Node.h"

Node* findSmallestNode(Node* n)
{
	while (n->left) n = n->left.get();
	return n;
}

Node* firstRightParent(Node* n)
{
	while(n->parent && n == n->parent->right.get()) n = n->parent;
	return n->parent;
}

Node* successor(Node* n)
{
	if (!n) return nullptr;

	if (n->right)
	{
		return findSmallestNode(n->right.get());
	}
	else
	{
		return firstRightParent(n);
	}
}

void successorTest()
{
    auto root = testableBST();

    assert(successor(root->get(5))->value == 6);
    assert(successor(root->get(4))->value == 5);
    assert(successor(root->get(8))->value == 10);
    assert(successor(root->get(6))->value == 8);
    assert(successor(root->get(2))->value == 3);
    assert(successor(root->get(3))->value == 4);
    assert(successor(root->get(10)) == nullptr);
}

int main()
{
    successorTest();
}
