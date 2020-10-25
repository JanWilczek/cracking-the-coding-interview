#include <vector>
#include <memory>
#include <list>
#include <queue>
#include <cassert>
#include <iostream>
#include <cmath>

using namespace std;


struct Node{
    Node(int val, unique_ptr<Node> l, unique_ptr<Node> r) : value{val}, left{move(l)}, right{move(r)} {}
    int value;
    unique_ptr<Node> left{nullptr}, right{nullptr};
};


int treeHeight(Node* root)
{
	if (!root) return 0;

	auto leftSubtreeHeight = treeHeight(root->left.get());
	auto rightSubtreeHeight = treeHeight(root->right.get());

	return std::max(leftSubtreeHeight, rightSubtreeHeight) + 1;
}

vector<list<Node*>> nodesAtEachDepth(Node* bstRoot)
{	
	auto height = treeHeight(bstRoot);

	vector<list<Node*>> nodesAt(height);

	queue<Node*> bfsQueue;
	bfsQueue.push(bstRoot);

	for (auto n = 0; n < height; ++n)
	{
		auto nodesAtLevel = pow(2, n);
		for (auto i = 0; i < nodesAtLevel; ++i)
        {
            auto node = bfsQueue.front();
		    bfsQueue.pop();

            if (node)
            {
                bfsQueue.push(node->left.get());
                bfsQueue.push(node->right.get());
                nodesAt[n].push_back(node);
            }
            else
            {
                bfsQueue.push(nullptr);
                bfsQueue.push(nullptr);
            }            
	    }
	}


	return nodesAt;
}


// Alternative
vector<list<Node*>> nodesAtEachDepth2(Node* bstRoot)
{	
	vector<list<Node*>> nodesAt;

	queue<Node*> bfsQueue;
	bfsQueue.push(bstRoot);

	auto level = 0;
	bool isLevelEmpty{!bstRoot};

	while (!isLevelEmpty && !bfsQueue.empty())
	{
		auto nodesOnTheLevel = pow(2, level);
		isLevelEmpty = true;

        while(nodesOnTheLevel--)
        {
			auto node = bfsQueue.front();
			bfsQueue.pop();

			if (node)
		    {
			    isLevelEmpty = false;
		        if (static_cast<typename decltype(nodesAt)::size_type>(level) >= nodesAt.size()) nodesAt.push_back(list<Node*>{});
			    bfsQueue.push(node->left.get());
			    bfsQueue.push(node->right.get());
			    nodesAt[level].push_back(node);
		    }
            else
		    {
			    bfsQueue.push(nullptr);
			    bfsQueue.push(nullptr);
		    }
		}

		++level;
	}

	return nodesAt;
}

void nodesAtEachDepthTest()
{
    unique_ptr<Node> balancedRoot = make_unique<Node>(0, make_unique<Node>(1, make_unique<Node>(3, nullptr, nullptr), make_unique<Node>(4,nullptr,nullptr)), make_unique<Node>(2,make_unique<Node>(5,nullptr,nullptr), nullptr));

    unique_ptr<Node> unbalancedRoot = make_unique<Node>(0, make_unique<Node>(1, make_unique<Node>(3, make_unique<Node>(6, nullptr, nullptr), make_unique<Node>(7, nullptr, nullptr)), make_unique<Node>(4,nullptr,nullptr)), make_unique<Node>(2,make_unique<Node>(5,nullptr,nullptr), nullptr));

    for (auto root : {balancedRoot.get(), unbalancedRoot.get()})
    {
        auto n1 = nodesAtEachDepth(root);
        auto n2 = nodesAtEachDepth2(root);

        for (auto& n : {n1, n2})
        {
            for (auto& level: n)
            {
                for (auto& node : level)
                {
                    cout << node->value << " ";
                }
                cout << endl;
            }
        }

        assert(n1 == n2);
    }
}

int main()
{
    nodesAtEachDepthTest();
}
