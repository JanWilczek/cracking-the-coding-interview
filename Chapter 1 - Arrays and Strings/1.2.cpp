#include <cstring>
#include <assert.h>

char* reverse(char* string)	// std::reverse
{
	auto length = strlen(string);
	
	for (decltype(length) i = 0; i < length / 2; ++i)
	{
		// std::swap(string[i], string[length - 1 - i]);
		auto& first = string[i];
		auto& second = string[length -1 -i];
        auto temp = first;
		first = second;
		second = temp;
	}
	
	return string;
}

int main()
{
    char abcd[] = "abcd";
    char abcde[] = "abcde";
    char empty[] = "";
    char* null = nullptr;

    reverse(abcd);
    assert(strcmp(abcd, "dcba") == 0);

    reverse(abcde);
    assert(strcmp(abcde, "edcba") == 0);

    reverse(empty);
    assert(strcmp(empty, "") == 0);

    reverse(null);
    assert(null == nullptr);

    return 0;
}