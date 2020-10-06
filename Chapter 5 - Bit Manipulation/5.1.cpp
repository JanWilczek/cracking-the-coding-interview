#include <cassert>

void setBitSubstring(int& N, int M, int i, int j)
{
    assert(M >> (j - i + 1) == 0);
    
	int allOnes = ~0;
	int halfMask = allOnes << (j+1);
	int fullMask = halfMask | (allOnes >> (32 - i));
	M = M << i;
	
	// Zero bits for M
	N = N & fullMask;

	// Assign M's bits
	N = N | M;
}

int main()
{
    int N = 0b10000000000;
    int M = 0b10101;
    int i = 2;
    int j = 6;
    int expectedOutput = 0b10001010100;

    setBitSubstring(N, M, i, j);
    assert(N == expectedOutput);
}
