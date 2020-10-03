#include <stack>
#include <cassert>
#include <iostream>

class MinStack
{
	std::stack<int> s;
	std::stack<int> minStack;

public:
	void push(int element)
	{
		if (minStack.empty() || element <= minStack.top())
		{
			minStack.push(element);
		}
		s.push(element);
	}
	
	int top()
	{
		return s.top();
	}
	
	void pop()
	{
		if (s.top() == minStack.top())
		{
			minStack.pop();
		}
		s.pop();
	}

	int min()
	{
		return minStack.top();
	}

    typename std::stack<int>::size_type size()
    {
        return s.size();
    }
};

int main()
{
    MinStack s;
    s.push(3);
    s.push(1);
    assert(s.min() == 1);
    s.push(2);
    assert(s.min() == 1);
    s.push(1);
    assert(s.min() == 1);
    s.pop();
    assert(s.min() == 1);
    s.push(0);
    assert(s.min() == 0);
    while (s.size() > 1) s.pop();
    assert(s.min() == 3);
}
