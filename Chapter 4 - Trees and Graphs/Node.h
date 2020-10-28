#include <memory>
#include <algorithm>

struct Node {
    Node(int val, Node* p, std::unique_ptr<Node> l = nullptr, std::unique_ptr<Node> r = nullptr) : value{val}, parent{p}, left{std::move(l)}, right{std::move(r)} {}
    Node(int val, std::unique_ptr<Node> l = nullptr, std::unique_ptr<Node> r = nullptr) : value{val}, parent{nullptr}, left{std::move(l)}, right{std::move(r)} {}
	int value;
	Node* parent;
	std::unique_ptr<Node> left, right;
    void insert(int val)
    {
        if (val >= value)
        {
            if (right)
            {
                right->insert(val);
            }
            else
            {
                right = std::make_unique<Node>(val, this);
            }
        }
        else
        {
            if (left)
            {
                left->insert(val);
            }
            else
            {
                left = std::make_unique<Node>(val, this);
            }
        }        
    }

    Node* get(int val)
    {
        if (value == val)
        {
            return this;
        }
        return val > value ? (right ? right->get(val) : nullptr) : (left ? left->get(val) : nullptr);
    }
};

int treeHeight(Node* root)
{
	if (!root) return 0;

	auto leftSubtreeHeight = treeHeight(root->left.get());
	auto rightSubtreeHeight = treeHeight(root->right.get());

	return std::max(leftSubtreeHeight, rightSubtreeHeight) + 1;
}

std::unique_ptr<Node> testableBST()
{
    std::unique_ptr<Node> root = std::make_unique<Node>(5, nullptr);
    for (auto i : {3, 8, 1, 4, 6, 10, 0, 2})
    {
        root->insert(i);
    }
    return root;
}

std::unique_ptr<Node> bigTestableBinaryTree()
{
    std::unique_ptr<Node> root = std::make_unique<Node>(5, nullptr);
    for (auto i : {3, 8, -1, -6, 1, 4, -2, 6, -1, 10, 0, 2, -4, -7, 4, -4, -1, 2})
    {
        root->insert(i);
    }
    return root;
}
