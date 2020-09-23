#include <string>
#include <iostream>
#include <ios>
#include <limits>
#include <assert.h>
#include <array>

using namespace std;

bool hasAllUniqueCharacters(const string& s)
{
	//	int characterCount[numeric_limits<char>::max()] = {0};
	array<int, numeric_limits<char>::max()+1> characterCount{};
	
	for (char c : s)
	{
		if (++characterCount[c] > 1)	return false;
	}
	return true;
}

bool hasAllUniqueCharactersLowMemory(const string& s)
{
	for (string::size_type i = 0; i < s.length(); ++i)
	{
		for (string::size_type j = i+1; j < s.length(); ++j)
		{
			if (s[j] == s[i]) return false;
		}
	}
	return true;
}

int main()
{
	string s_test = "test";
	cout << "Does string s has all unique characters? " << boolalpha << hasAllUniqueCharacters(s_test) << endl;
	assert(hasAllUniqueCharacters(s_test) == false);
	assert(hasAllUniqueCharacters("abcdefghijk") == true);
	assert(hasAllUniqueCharacters("") == true);

	assert(hasAllUniqueCharactersLowMemory(s_test) == false);
	assert(hasAllUniqueCharactersLowMemory("abcdefghijk") == true);
	assert(hasAllUniqueCharactersLowMemory("") == true);
	return 0;
}

