#include <algorithm>
#include <cmath>
#include <cassert>

struct Node{
    Node *left{nullptr}, *right{nullptr};
};

int treeHeight(Node* root, bool& isBalanced)
{
	if (!root) return 0;

	auto leftSubtreeHeight = treeHeight(root->left, isBalanced);
	auto rightSubtreeHeight = treeHeight(root->right, isBalanced);

	if (std::abs(leftSubtreeHeight - rightSubtreeHeight) > 1) isBalanced= false;

	return std::max(leftSubtreeHeight, rightSubtreeHeight) + 1;
}

bool isBalanced(Node* root)
{
	bool result = true;
	treeHeight(root, result);
	return result;
}

void destroyTree(Node* root)
{
    if (root->right)
    {
        destroyTree(root->right);
        delete root->right;
    }

    if (root->left)
    {
        destroyTree(root->left);
        delete root->left;
    }
}

void isBalancedTest()
{
    Node* unbalanced = new Node{new Node{new Node{new Node, nullptr}, nullptr}, new Node};
    Node* balanced = new Node{new Node{new Node, nullptr}, new Node};

    assert(!isBalanced(unbalanced));
    assert(isBalanced(balanced));

    destroyTree(unbalanced);
    delete unbalanced;

    destroyTree(balanced);
    delete balanced;
}

int main()
{
    isBalancedTest();
}
