#include <vector>
#include <numeric>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

struct Node {
	int value;
	Node *left{nullptr}, *right{nullptr};
};


Node* constructNode(vector<int> sortedArray, int begin, int end)
{
    if (end == begin) return new Node{sortedArray[begin]};

    auto middle = (end + begin) / 2;
    cout << middle << endl;
    return new Node{sortedArray[middle], constructNode(sortedArray, begin, middle), constructNode(sortedArray, middle + 1, end)};
}

Node* constructMinHeightBinaryTree(vector<int> sortedArray)
{
	return constructNode(sortedArray, 0, sortedArray.size());
}


bool isBST(Node* n)
{
    if (!n) return true;

    bool result = true;
    if (n->left && n->left->value > n->value) result = false;
    if (n->right && n->right->value < n->value) result = false;

    return result && isBST(n->left) && isBST(n->right);
}

int treeHeight(Node* root)
{
	if (!root) return 0;

	auto leftSubtreeHeight = treeHeight(root->left);
	auto rightSubtreeHeight = treeHeight(root->right);

	return std::max(leftSubtreeHeight, rightSubtreeHeight) + 1;
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

template <typename F>
void inOrder(Node* head, F&& f)
{
    if (!head) return;

    inOrder(head->left, f);
    f(head);
    inOrder(head->right, f);
}

void testConstructMinHeightBT()
{
    vector<int> values(9);
    std::iota(values.begin(), values.end(), 0);

    auto head = constructMinHeightBinaryTree(values);
    inOrder(head, [](Node*& n) {cout << n->value << " ";});
    // assert(isBST(head));
    auto height = treeHeight(head);
    assert(height <= std::log2(values.size()));

    destroyTree(head);
    delete head;

    cout << "Success!\n";
}

int main()
{
    testConstructMinHeightBT();
}
