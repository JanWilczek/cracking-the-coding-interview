#include <string>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

void removeDuplicates2(string& s)
{
	for (string::size_type i = 0; i < s.length(); ++i)
	{
		for (string::size_type j = i+1; j < s.length(); ++j)
		{
			while (s[j] == s[i]) s.erase(s.begin() + j);
		}
	}
}

void removeDuplicates3(string& s)
{
	std::sort(s.begin(), s.end());
	for (string::size_type i = 1; i < s.length(); ++i)
	{
		while(s[i] == s[i-1]) s.erase(s.begin() + i);
	}
}

void removeDuplicates(string& s2)
{
	if (s2.length() < 2) return;

	char* s = new char[s2.length() + 1];
	strcpy(s, s2.c_str());

	if (!s || !(s[0])) return;

	char* tail = s + 1;

	for (char* c = tail; *c; ++c)
	{
		char* c2 = s;
		while (c2 != tail)
		{
			if (*c2 == *c) break;
			++c2;
		}
		if (c2 == tail){
			*tail++ = *c;
		}
	}

	*tail = 0;

	s2 = string{s};
	delete[] s;
}


void testRemoveDuplicatesEmpty()
{
	string empty{};
    removeDuplicates(empty);
	assert(empty==string{});	
}

void testRemoveDuplicatesOneCharacter()
{
	string oneCharacter{"a"};
	removeDuplicates(oneCharacter);
	assert(oneCharacter == "a");
}

void testRemoveDuplicatesSorted()
{
	string sorted{"aaabbbbbbccdeeee"};
	removeDuplicates(sorted);
	assert(sorted == "abcde");
}

void testRemoveDuplicatesUniqueCharacters()
{
	string uniqueCharacters{"ghijklmnop"};
	string uniqueCharacters2 = uniqueCharacters;
	removeDuplicates(uniqueCharacters);
	assert(uniqueCharacters == uniqueCharacters2);
}

void testRemoveDuplicatesNormalString()
{
	string s{"mathematics"};
	removeDuplicates(s);
	sort(s.begin(), s.end());
	assert(s == "acehimst");
}

void testRemoveDuplicatesAllDuplicates()
{
	string s{"aaaaaa"};
	removeDuplicates(s);
	assert(s == "a");
}

int main()
{
    testRemoveDuplicatesEmpty();
    testRemoveDuplicatesOneCharacter();
    testRemoveDuplicatesSorted();
    testRemoveDuplicatesUniqueCharacters();
    testRemoveDuplicatesNormalString();
	testRemoveDuplicatesAllDuplicates();

    return 0;
}
