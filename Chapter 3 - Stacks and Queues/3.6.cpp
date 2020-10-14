#include <stack>
#include <iostream>
#include <cassert>


std::stack<int> sortStack(std::stack<int>& s)
{
    using namespace std;
	
    stack<int> result;
    while (!s.empty())
    {
        auto tmp{s.top()};
        s.pop();
        while (!result.empty() && tmp > result.top())
        {
            s.push(result.top());
            result.pop();
        }
        result.push(tmp);
    }
    return result;
}	

void sortStackTest()
{
    using namespace std;

    stack<int> s;
    s.push(5); s.push(2); s.push(4); s.push(3); s.push(1);

    auto sortedS = sortStack(s);

    for (int i = 1; i <= 5; ++i)
    {
        assert(sortedS.top() == i);
        sortedS.pop();
    }
}

int main()
{
    sortStackTest();
}
