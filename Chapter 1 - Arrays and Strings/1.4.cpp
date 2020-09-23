#include <assert.h>

bool areAnagrams(const char* s1, const char* s2)
{
	if (!s1 && !s2) return true;
	if (!s1 || !s2) return false; 

	constexpr int NUM_CHARACTERS = 1 << 8*sizeof(char);
    int* characterCount = new int[NUM_CHARACTERS]{};
	while(*s1)
	{
		++characterCount[*s1++];    // would require tolower() for the case-insensitive version
	}

	while(*s2)
	{
		--characterCount[*s2++];    // would require tolower() for the case-insensitive version
	}

	bool result = true;
	for (int i = 0; i < NUM_CHARACTERS; ++i)
	{
		if (characterCount[i] != 0)
		{
			result = false;
			break;
		}
	}

	delete[] characterCount;

	return result;
}

int main()
{
    assert(areAnagrams("Ania", "niAa"));
    assert(!areAnagrams("Jan", "Ania"));
    assert(!areAnagrams("Ania", "niaa"));
    assert(areAnagrams("ania", "niaa"));
}
