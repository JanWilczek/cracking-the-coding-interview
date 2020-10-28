#include <stdexcept>

constexpr int findRightmost(unsigned int digit, unsigned int number, int startPosition=0)
{
	if (digit == 1 && number == 0)
	{
		throw std::invalid_argument{"findRightmost(1,0)"};
	}

	number >>= startPosition;
	while (number % 2 != digit)
	{
		++startPosition;
		number >>= 1;
	}

	return startPosition;
}

[[nodiscard]] constexpr unsigned int flipBit(unsigned int a, int position)
{
	return a ^ (1 << position);
}

constexpr unsigned int nextLargestFromOnes(unsigned int a)
{
	if (a == 0)
	{
		throw std::invalid_argument{"nextLargestFromOnes(0)"};
	}

	// Find rightmost 1
	auto rightmost1_id = findRightmost(1, a);

	// Find the first 0 after that
	auto rightmost0_id = findRightmost(0, a, rightmost1_id);

	// Turn on the 0
	a = flipBit(a, rightmost0_id);

	// Turn off the neighbouring 1
	auto right1_id = rightmost0_id - 1;
	a = flipBit(a, right1_id );

	// Move ones on the right of the zero as far as possible to the right
	auto mask = (1 << right1_id) - 1;
	auto tail = a & mask;
	tail >>= rightmost1_id;
	a &= (~mask);
	a |= tail;

	return a;
}

constexpr unsigned int nextSmallestFromOnes(unsigned int a)
{
    if (a == 0)
	{
		throw std::invalid_argument{"nextSmallestFromOnes(0)"};
	}

	// Find the rightmost 0
	auto rightmost0_id = findRightmost(0, a);

	// Find the first 1 after that
	auto rightmost1_id = findRightmost(1, a, rightmost0_id);

	// Turn off 1
	a = flipBit(a, rightmost1_id);

	// Turn on 0 on the right of that 1
	auto right0_id = rightmost1_id-1;
	a = flipBit(a, right0_id );

	// Move the ones on the right of that 0 as far left as possible (maximize tail)
	auto mask = (1 << right0_id) - 1;
	auto tail = a & mask;
	tail <<= right0_id - rightmost0_id;
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
