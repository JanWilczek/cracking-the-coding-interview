#include <vector>
#include <numeric>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int value;
	Node *left{nullptr}, *right{nullptr};
};


Node* constructNode(vector<int> sortedArray, int begin, int end)
{
    if (end == begin) return new Node{sortedArray[begin]};

    auto middle = (end + begin) / 2;
    
    auto leftChild = middle == begin ? nullptr : constructNode(sortedArray, begin, middle);
    auto rightChild = middle + 1 == end ? nullptr : constructNode(sortedArray, middle + 1, end);

    return new Node{sortedArray[middle], leftChild, rightChild };
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
void inOrder(Node* node, F&& f)
{
    if (!node) return;

    inOrder(node->left, f);
    f(node);
    inOrder(node->right, f);
}

void printTree(Node* root)
{
    int nb_spaces_bottom = 5;

    auto height = treeHeight(root);
    queue<Node*> bfsQueue;
    bfsQueue.push(root);

    for (auto n = 0; n < height; ++n)
    {
        int nodesOnTheLevel = std::pow(2, n);
        int nb_spaces = n == height-1 ? nb_spaces_bottom : (nb_spaces_bottom + 1) * std::pow(2, height-n-1);
        
        for (auto s = 0; s < nb_spaces / 2 + 1; ++s) cout << ' ';

        for (auto i = 0; i < nodesOnTheLevel; ++i)
        {
            auto node = bfsQueue.front();
            bfsQueue.pop();

            if (node)
            {
                bfsQueue.push(node->left);
                bfsQueue.push(node->right);
                cout << node->value;
            }
            else
            {
                cout << ' ';
            }            

            for (auto s = 0; s < nb_spaces; ++s) cout << ' ';
        }

        cout << endl;
    }
}

void testConstructMinHeightBT()
{
    vector<int> values(10);
    std::iota(values.begin(), values.end(), 0);

    auto root = constructMinHeightBinaryTree(values);

    inOrder(root, [](Node*& n) {cout << n->value << " ";});
    cout << endl;
    
    assert(isBST(root));
    
    printTree(root);
    
    auto height = treeHeight(root);
    auto lowerBoundOnHeight = std::floor(std::log2(values.size()));
    auto upperBoundOnBalancedHeight = lowerBoundOnHeight + 1;
    assert(height <= upperBoundOnBalancedHeight);

    destroyTree(root);
    delete root;

    cout << "Success!\n";
}

int main()
{
    testConstructMinHeightBT();
}
