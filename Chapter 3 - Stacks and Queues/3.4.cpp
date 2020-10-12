#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

void printTowers(vector<stack<int>> towers)
{
    cout << "------------------\n";
    auto maxSize = max(max(towers[0].size(), towers[1].size()), towers[2].size());

    while (maxSize)
    {
        for (auto& t : towers)
        {
            if (t.size() == maxSize)
            {
                cout << t.top() << '\t';
                t.pop();
            }
            else
            {
                cout << " \t";
            }            
        }
        cout << endl;
        --maxSize;
    }
}

vector<stack<int>> prepareHanoi(int N)
{
	vector<stack<int>> stacks(3);
	for (auto i = N; i > 0; --i)
	{
		stacks[0].push(i);
	}
	return stacks;
}

void hanoi(vector<stack<int>>& s, int origin, int destination, int helper)
{
    printTowers(s);
	if (s[destination].empty() || s[destination].top() > s[origin].top())
	{
		s[destination].push(s[origin].top());
		s[origin].pop();
	}
	else
	{
		hanoi(s, destination, helper, origin);
        hanoi(s, origin, destination, helper);
        hanoi(s, helper, destination, origin);
	}	
}

void solveHanoi(int N)
{
    auto towers = prepareHanoi(N);
    while (!towers[0].empty())
    {
        hanoi(towers, 0, 2, 1);
    }
    printTowers(towers);
}

int main()
{
    int N = 5;
    solveHanoi(N);
}
