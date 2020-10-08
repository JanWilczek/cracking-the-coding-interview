#include <string>
#include <iostream>
#include <cmath>

void decimalToBinary(const std::string& s)
{
	char digit;
	std::string result{""};
	int beforeDecimalPoint = 0;
	
	std::string::size_type i = 0;
	for (;i < s.size() && s[i] != '.'; ++i)
	{
		digit = s[i] - '0';
        beforeDecimalPoint = 10 * beforeDecimalPoint + digit;
	}
	
	while (beforeDecimalPoint)
	{
		if (beforeDecimalPoint % 2 == 1)
		{
			result = '1' + result;
		}
		else
		{
			result = '0' + result;
		}
		beforeDecimalPoint /= 2;
	}

	auto numDigitsAfterDecimalPoint = s.size() - i - 1;
	int afterDecimalPoint = 0;
	if (i < s.size())
	{
		if (s[i] == '.') 
        {
            result += '.';
            ++i;
        }

        for(;i < s.size(); ++i)
        {
            digit = s[i] - '0';
            afterDecimalPoint = 10 * afterDecimalPoint + digit;
        }
	
        float afterDecimalPointAccurate = afterDecimalPoint / std::pow(10.0f, numDigitsAfterDecimalPoint);

        while (numDigitsAfterDecimalPoint--)
        {
            afterDecimalPointAccurate *= 2.0f;
            if (afterDecimalPointAccurate >= 1.0f)
            {
                result += '1';
                afterDecimalPointAccurate -= 1.0f;
            }
            else
            {
                result += '0';
            }
        }

        if (afterDecimalPointAccurate)
        {
            std::cout << "ERROR\n";
            return;
        }	
	}

	std::cout << result << std::endl;
}

int main()
{
    decimalToBinary("1");
    decimalToBinary("2");
    decimalToBinary("3");
    decimalToBinary("4");
    decimalToBinary("10");
    decimalToBinary("10.5");
    decimalToBinary("10.25");
    decimalToBinary("10.3");
}
