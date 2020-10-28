#include "Node.h"
#include <cassert>

bool equalTrees(Node* root1, Node* root2)
{
	if (!root1 && !root2) return true;

	if (!root1 || !root2) return false;

	if (root1->value != root2->value) return false;

	return equalTrees(root1->left.get(), root2->left.get()) && equalTrees(root1->right.get(), root2->right.get());
}

bool isSubtree(Node* larger, Node* smaller)
{
	if (!smaller) return true;

	if (!larger) return false;

	return equalTrees(larger, smaller) || isSubtree(larger->left.get(), smaller) || isSubtree(larger->right.get(), smaller);
}

void isSubtreeTest()
{
    auto larger = bigTestableBinaryTree();
    auto smaller = testableBST();

    assert(isSubtree(smaller.get(), smaller->get(6)));
    assert(!isSubtree(larger.get(), smaller.get()));
}

int main()
{
    isSubtreeTest();
}
