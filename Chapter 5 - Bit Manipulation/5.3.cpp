#include <stdexcept>

constexpr unsigned int nextLargestFromOnes(unsigned int a)
{
	if (a == 0)
	{
		throw std::invalid_argument{"nextLargestFromOnes(0)"};
	}

	// Find rightmost 1
	auto a_copy = a;
	auto rightmost1_id = 0;
	while (a_copy % 2 == 0)
	{
		++rightmost1_id;
		a_copy >>= 1;
	}

	// Find the first 0 after that
	auto rightmost0_id = rightmost1_id;
	while (a_copy % 2 == 1)
	{
		++rightmost0_id;
		a_copy >>= 1;
	}

	// Turn on the 0
	a ^= 1 << rightmost0_id;

	// Turn off the neighbouring 1
	a ^= 1 << (rightmost0_id - 1);

	// Move ones on the right of the zero as far as possible to the right
	auto mask = (1 << rightmost0_id) - 1;
	auto tail = a & mask;
	tail >>= rightmost1_id;
	a &= (~mask);
	a |= tail;

	return a;
}

void nextLargestFromOnesTest()
{
    static_assert(nextLargestFromOnes(0b11010u) == 0b11100u);
    static_assert(nextLargestFromOnes(0b110010u) == 0b110100u);
    static_assert(nextLargestFromOnes(0b1101u) == 0b1110u);
    static_assert(nextLargestFromOnes(0b1110u) == 0b10011u);
    static_assert(nextLargestFromOnes(0b1001u) == 0b1010u);
    static_assert(nextLargestFromOnes(0b11001u) == 0b11010u);
    static_assert(nextLargestFromOnes(0b11001u) == 0b11010u);
    static_assert(nextLargestFromOnes(0b110001u) == 0b110010u);
    static_assert(nextLargestFromOnes(0b110110u) == 0b111001u);
    static_assert(nextLargestFromOnes(0b1100111u) == 0b1101011u);
}

int main()
{
    nextLargestFromOnesTest();
}
