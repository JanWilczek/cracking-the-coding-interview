#include <cassert>
#include <exception>
#include "Node.h"

Node* commonParent(Node* n1, Node* n2)
{
	while (n1)
	{
		auto runner = n2;
		while (runner)
		{
			if (runner == n1) return runner;
			runner = runner->parent;
		}
		n1 = n1->parent;
	}
	std::terminate();   // This should never be reached.
}

void commonParentTest()
{
    auto head = testableBST();

    assert(commonParent(head->get(2), head->get(10)) ==  head->get(5));
    assert(commonParent(head->get(0), head->get(2)) ==  head->get(1));
    assert(commonParent(head->get(0), head->get(4)) ==  head->get(3));
    assert(commonParent(head->get(5), head->get(10)) ==  head->get(5));
}

int main()
{
    commonParentTest();
}
