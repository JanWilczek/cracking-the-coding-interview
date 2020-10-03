#include <vector>
#include <stdexcept>
#include <iostream>
#include <iterator>

struct Node{
int data; int next=-1;
};

std::ostream& operator<<(std::ostream& os, const Node& n)
{
    os << n.data;
    return os;
}

struct ArrayStack
{
	std::vector<Node> array{ Node{0,0}, Node{0,1}, Node{0,2} };
	
	void push(int stackId, int data)
	{
        if (stackId < 0 || stackId > 2) throw std::runtime_error{"Invalid stack id."};
        int top = array[stackId].next;
        int newTop = top + 3;
        if (newTop > array.size()) array.resize(2*array.size());
        array[newTop] = Node{data, top};
        array[stackId].next = newTop;
	}

	int pop(int stackId)
	{
        if (stackId < 0 || stackId > 2) throw std::runtime_error{"Invalid stack id."};
        int top = array[stackId].next;
        if (top == stackId) throw std::out_of_range{"Empty stack!"};
        int data = array[top].data;
        array[stackId].next = array[top].next; // or array[stackId].next -= 3;
        return data;
	}
};

int main()
{
    ArrayStack s{};
    s.push(0,1);
    s.push(0,4);
    s.push(0,7);
    s.push(1,2);
    s.push(1,5);
    s.push(2,3);
    s.push(2,6);
    std::copy(s.array.begin(), s.array.end(), std::ostream_iterator<Node>(std::cout, " "));
}
