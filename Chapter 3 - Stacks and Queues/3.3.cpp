#include <stack>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <cassert>

template <typename T>
class SetOfStacks
{
public:
	using element_type = T;
	using size_type = typename std::stack<T>::size_type;

	explicit SetOfStacks(typename std::stack<T>::size_type thresh) : threshold{thresh}, stacks{std::vector<std::stack<T>>(1)} {}

    SetOfStacks(const SetOfStacks&)=default;
    SetOfStacks(SetOfStacks&&)=default;
    SetOfStacks& operator=(const SetOfStacks&)=default;
    SetOfStacks& operator=(SetOfStacks&&)=default;

	T pop();
    T popAt(size_type index);
    T popAtWithRollover(size_type index);
	void push(T element);
    bool empty();

private:
	void rollover(std::stack<T>& to, std::stack<T>& from);

	typename std::stack<T>::size_type threshold;
	typename std::vector<std::stack<T>>::size_type currentStack{0};
	std::vector<std::stack<T>> stacks; 
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

template <typename T>
T SetOfStacks<T>::popAtWithRollover(size_type index)
{
	if (index == currentStack) return pop();

	if (index > currentStack) throw std::out_of_range{"Incorrect stack index!"};
	
	if (empty()) throw std::runtime_error{"Cannot pop from empty stack!"};

	T result{stacks[index].top()};
	stacks[index].pop();

	for (auto i = index; i < currentStack; ++i)
	{
		rollover(stacks[i], stacks[i+1]);
	}
	
	if (stacks[currentStack].empty()) --currentStack;

	// For testing purposes
	for (auto it = stacks.cbegin(); stacks.size() > 2 && it != stacks.cbegin() + currentStack - 1; ++it)
	{
		assert(it->size() == (it+1)->size());
	}

	return result;	
}

template <typename T>
void SetOfStacks<T>::rollover(std::stack<T>& to, std::stack<T>& from)
{
	std::stack<T> helper;
	
	while (!from.empty())
	{
		helper.push(from.top());
		from.pop();
	}

	to.push(helper.top());
	helper.pop();

	while (!helper.empty())
	{
		from.push(helper.top());
		helper.pop();
	}
}


int main()
{
    SetOfStacks<int> ss{2};

    ss.push(1);
    ss.push(2);
    ss.push(3);
    ss.push(4);
    ss.push(5);

    SetOfStacks<int> ss2{ss};

    std::cout << ss.popAt(1) << " " << ss.popAt(1) << std::endl;

    ss.push(6);

    while (!ss.empty())
    {
        std::cout << ss.pop() << " ";
    }

	std::cout << std::endl;

    std::cout << ss2.popAtWithRollover(1) << std::endl;

    while(!ss2.empty())
    {
        std::cout << ss2.pop() << " ";
    }
}
