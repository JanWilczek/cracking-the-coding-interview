#include <cassert>


int fibonacci(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacci_recursive(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}

	int n2 = 1;
	int n1 = 1;
	int current = 1;

	for (int i = 2; i <= n; ++i)
	{
		current = n1 + n2;
		n2 = n1;
		n1 = current;
	}

	return current;
}

int main()
{
    for (int n = 0; n < 10; ++n)
    {
        assert(fibonacci(n) == fibonacci_recursive(n));
    }

}