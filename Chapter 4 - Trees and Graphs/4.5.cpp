#include <memory>
#include <cassert>

struct Node {
    Node(int val, Node* p, std::unique_ptr<Node> l = nullptr, std::unique_ptr<Node> r = nullptr) : value{val}, parent{p}, left{std::move(l)}, right{std::move(r)} {}
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
    std::unique_ptr<Node> root = std::make_unique<Node>(5, nullptr);
    for (auto i : {3, 8, 1, 4, 6, 10, 0, 2})
    {
        root->insert(i);
    }

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
