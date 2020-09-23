#include <iostream>

int main()
{
    int n = 10;

    int* a = new int[n];    // UNINITIALIZED

    int* b = new int[n]{};  // INITIALIZED TO 0

    int* c = new int[n]();  // INITIALIZED TO 0

    std::cout << "a \t b \t c" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << a[i] << '\t' << b[i] << '\t' << c[i] << std::endl;
    }
}
