#include <string>
#include <assert.h>
#include <algorithm>

bool isSubstring(const std::string& s1, const std::string& s2)
{
    return std::search(s1.begin(), s1.end(), s2.begin(), s2.end()) != s1.end();
}

bool isRotation(const std::string& s1, const std::string& s2)
{
	if (s1.length() != s2.length()) return false;
	if (s1.length() == 0) return true;

	std::string s1s1 = s1 + s1;
	return isSubstring(s1s1, s2);	// is s2 a substring of s1?
}


int main()
{
    assert(isRotation("erbottlewat", "waterbottle"));
    assert(!isRotation("erbottlewat", "waterbottlk"));
    assert(!isRotation("bottlewat", "waterbottle"));
    assert(!isRotation("apple", "paple"));
    return 0;
}
