#include <vector>
#include <limits>
#include <cassert>

using namespace std;
using uint = unsigned int;

bool fetchBitOfA(const vector<uint>& A, uint element, uint bit)
{
	return (A[element] & (1u << bit)) > 0u;
}

uint findMissing(const vector<uint>& A)
{
	auto n = A.size();
	auto sum = 0u;

	for (auto i = 0u; i < A.size(); ++i)
	{
		for (auto j = numeric_limits<uint>::digits - 1; j >= 0; --j)
		{
			if (fetchBitOfA(A, i, j))
			{
				sum += 1u << j;
			}
		}
	}

	auto completeSum = uint{n * (n+1) / 2u};
	return completeSum - sum;
}

uint findMissing2(const vector<uint>& A, uint bit)
{
	if (bit == numeric_limits<uint>::digits) return 0u;

	vector<uint> candidatesWith0LSB, candidatesWith1LSB;
	for (auto i = 0u; i < A.size(); ++i)
	{
		if (fetchBitOfA(A, i, bit)) candidatesWith1LSB.push_back(A[i]); // IMO against the rules
else candidatesWith0LSB.push_back(A[i]);	
	}

	if (candidatesWith0LSB.size() > candidatesWith1LSB.size())
	{
		// the missing number has LSB == 1
		return (findMissing2(candidatesWith1LSB, bit + 1) << 1) | 1;
	}
else
	{
		// the missing number has LSB == 0
		return (findMissing2(candidatesWith0LSB, bit + 1) << 1) | 0;
	}
}

uint findMissing2(const vector<uint>& A)
{
	return findMissing2(A, 0u);
}


void testFindMissing()
{
    vector<uint> A{0u, 1u, 3u};
    assert(findMissing(A) == 2u);
    assert(findMissing2(A) == 2u);

    A = {2u, 3u, 1u};
    assert(findMissing(A) == 0u);
    assert(findMissing2(A) == 0u);

    A = {2u, 0u, 1u};
    assert(findMissing(A) == 3u);
    assert(findMissing2(A) == 3u);
}

int main() 
{
    testFindMissing();
}
