#include <list>
#include <iostream>
#include "Node.h"

using namespace std;

using path_iterator = typename list<Node*>::iterator;

void printPath(path_iterator b, path_iterator e)
{
	while (b != e)
	{
		cout << (*b++)->value << " ";
	}
	cout << endl;
}

void checkIfPathOrSubpathSumsUpTo(int value, list<Node*>& path, int initialSum)
{
	auto& last = path.back();

    initialSum += last->value;

	auto newStart = path.begin();
	auto sum = initialSum;
	
	// "eat the tail"
	while (newStart != path.end())
	{
		if (sum == value)
		{
			printPath(newStart, path.end());
		}
		sum -= (*newStart)->value;
		++newStart;
	}
	
	if (last->left)
	{
        path.push_back(last->left.get());
        checkIfPathOrSubpathSumsUpTo(value, path, initialSum);
        path.pop_back();
    }

    if (last->right)
    {
        path.push_back(last->right.get());
        checkIfPathOrSubpathSumsUpTo(value, path, initialSum);
        path.pop_back();
	}
}

void printAllPathsSummingUpTo(int value, Node* root)
{
	if (!root) return;

    list<Node*> path{root};

	checkIfPathOrSubpathSumsUpTo(value, path, 0);
}

void printAllPathsSummingUpToTest()
{
    auto root = testableBST();
    printAllPathsSummingUpTo(4, root.get());
    cout << endl;
    root = bigTestableBinaryTree();
    printAllPathsSummingUpTo(4, root.get());
}

int main()
{
    printAllPathsSummingUpToTest();
}
