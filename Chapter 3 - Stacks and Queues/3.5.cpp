#include <stack>
#include <iostream>


template <typename T>
class MyQueue {
public:
	using size_type = typename std::stack<T>::size_type;
	using element_type = T;
	
	size_type size() const;
	bool empty() const;
	void push(T element);
	T pop();

private:
	std::stack<T> pushStack;
	std::stack<T> popStack;
};



template <typename T>
typename MyQueue<T>::size_type MyQueue<T>::size() const
{
	return pushStack.size() + popStack.size();
}

template <typename T>
bool MyQueue<T>::empty() const
{
	return pushStack.empty() && popStack.empty();
}

template <typename T>
void MyQueue<T>::push(T element)
{
	pushStack.push(element);
}

template <typename T>
T MyQueue<T>::pop()
{
	if (popStack.empty())
	{
		while (!pushStack.empty())
		{
			popStack.push(std::move(pushStack.top()));
			pushStack.pop();
		}
	}

	T result{std::move(popStack.top())};
	popStack.pop();
	return result;
}


int main()
{
    MyQueue<int> q;
    for (int i = 1; i < 6; ++i)
    {
        q.push(i);
    }

    std::cout << q.pop() << " " << q.pop() << std::endl;

    q.push(6);
    q.push(7);

    while (!q.empty())
    {
        std::cout << q.pop() << " ";
    }
}
