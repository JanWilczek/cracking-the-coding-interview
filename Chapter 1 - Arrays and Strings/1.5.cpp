#include <iostream>
#include <string>

char* replaceSpace(char* s)
{
	if (!s) return nullptr;
    
	int length = 0;
    int spaceCount = 0;

	char* s2 = s;
	while (*s2)
	{
		if (std::isspace(*s2++)) ++spaceCount;
		++length;
	}
	
	int newLength = length + 2 * spaceCount + 1;
	char* new_s = new char[newLength];

	int new_i = 0;
	for (int i = 0; i < length; ++i)
	{
		if (std::isspace(s[i]))
		{
			new_s[new_i++] = '%';
			new_s[new_i++] = '2';
			new_s[new_i++] = '0';
		}
		else
		{
			new_s[new_i++] = s[i];
		}
	}
	new_s[new_i] = '\0';

	return new_s;
}


int main()
{
    char s[] = "  Hello    World!  ";
    auto s2 = replaceSpace(s);
    std::cout << s2 << std::endl;
    delete[] s2;
    return 0;
}
