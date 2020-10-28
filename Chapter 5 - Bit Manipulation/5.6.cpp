#include <limits>

constexpr unsigned int swapOddAndEven(unsigned int a)
{
	for (auto i = 0ull; i < std::numeric_limits<unsigned int>::digits; i += 2)
	{
		auto mask = 0b11u << i;
		auto tmp = a & mask;
		auto isSwapNecessary = tmp && (tmp & (tmp - 1)) == 0; // tmp has only one 1 and is different from 0
		if (isSwapNecessary)
		{
			a ^= mask;
		}
	}

    return a;
}

// assuming we have 32 bits…
constexpr unsigned int swapOddAndEven2(unsigned int a)
{
	auto maskOdd = 0b10101010101010101010101010101010u;
	auto maskEven = maskOdd >> 1;

	return ((a & maskOdd) >> 1) | ((a & maskEven) << 1);
}

void swapOddAndEvenTest()
{
    static_assert(swapOddAndEven(0b11010u) == 0b100101u);
    static_assert(swapOddAndEven(0b010011u) == 0b100011u);
    static_assert(swapOddAndEven(0b110100u) == 0b111000u);

    static_assert(swapOddAndEven2(0b11010u) == 0b100101u);
    static_assert(swapOddAndEven2(0b010011u) == 0b100011u);
    static_assert(swapOddAndEven2(0b110100u) == 0b111000u);
}

int main()
{}
