#include <stack>
#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T>
class SetOfStacks
{
	using element_type = T;
	using size_type = typename std::stack<T>::size_type;

	typename std::stack<T>::size_type threshold;
	typename std::vector<std::stack<T>>::size_type currentStack{0};
	std::vector<std::stack<T>> stacks; 
public:
	explicit SetOfStacks(typename std::stack<T>::size_type thresh) : threshold{thresh}, stacks{std::vector<std::stack<T>>(1)} {}

    SetOfStacks(const SetOfStacks&)=default;
    SetOfStacks(SetOfStacks&&)=default;
    SetOfStacks& operator=(const SetOfStacks&)=default;
    SetOfStacks& operator=(SetOfStacks&&)=default;

	T pop();
    T popAt(size_type index);
	void push(T element);
    bool empty();
};

template <typename T>
T SetOfStacks<T>::pop()
{
	if (empty())
	{
		throw std::out_of_range{"Cannot pop from empty stack!"};
	}

	T result{stacks[currentStack].top()};
	stacks[currentStack].pop();

	// if (stacks[currentStack].empty())
	// {
	//      if (currentStack > size_type{0}) --currentStack;
	// }

    // For the follow-up:
    while (currentStack > size_type{0} && stacks[currentStack].empty())
	{
		--currentStack;
	}

	return result;
}

template <typename T>
void SetOfStacks<T>::push(T element)
{
	if (stacks[currentStack].size() == threshold)
	{
		++currentStack;
		if (currentStack >= stacks.size())
		{
			stacks.push_back(std::stack<T>{});
		}
	}

	stacks[currentStack].push(std::move(element));
}


template <typename T>
bool SetOfStacks<T>::empty()
{
	return currentStack == size_type{0} && stacks[currentStack].empty();
}

template <typename T>
T SetOfStacks<T>::popAt(size_type index)
{
	if (index >= stacks.size())
	{
		throw std::out_of_range{"Invalid stack index!"};
	}

	if (stacks[index].empty())
	{
		throw std::runtime_error{"Cannot pop from empty stack!"};
	}

	if (index == currentStack) return pop();
	
	T result{stacks[index].top()};
	stacks[index].pop();

	return result;
}


int main()
{
    SetOfStacks<int> ss{2};

    ss.push(1);
    ss.push(2);
    ss.push(3);
    ss.push(4);
    ss.push(5);

    std::cout << ss.popAt(1) << " " << ss.popAt(1) << std::endl;

    ss.push(6);

    SetOfStacks<int> ss2{ss};

    while (!ss.empty())
    {
        std::cout << ss.pop() << std::endl;
    }

    while(!ss2.empty())
    {
        std::cout <<ss2.pop() << std::endl;
    }
}
