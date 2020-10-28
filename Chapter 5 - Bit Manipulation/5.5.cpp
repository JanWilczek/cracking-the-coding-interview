constexpr int bitDiff(unsigned int a, unsigned int b)
{
	auto differentBits = a ^ b;
	
	auto differentCount = 0;

	while(differentBits)
	{
		differentCount += differentBits % 2;
		differentBits >>= 1;
	}

	return differentCount;
}

void bitDiffTest()
{
    static_assert(bitDiff(31, 14) == 2);
    static_assert(bitDiff(0b1101, 0b1001) == 1);
    static_assert(bitDiff(0b1101, 0b1000) == 2);
    static_assert(bitDiff(0b101101, 0b111000) == 3);
    static_assert(bitDiff(0b101101, 0b110000) == 4);
    static_assert(bitDiff(0b101101, 0b10) == 5);
    static_assert(bitDiff(0b10110100, 0b11000011) == 6);
    static_assert(bitDiff(0b1111111, 0b0) == 7);
    static_assert(bitDiff(0b10110110110, 0b1) == 8);
}

int main()
{}
