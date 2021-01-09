#include <cassert>
#include <iostream>

namespace original
{
    int possiblePaths(int row, int column)
    {
        if (row == 0 || column == 0)
            return 1;

        return possiblePaths(row - 1, column) + possiblePaths(row, column - 1);
    }

    int possiblePaths(int n)
    {
        // target field is (0,0), start field is (n-1, n-1).
        return possiblePaths(n - 1, n - 1);
    }
} // namespace original

namespace follow_up
{
    constexpr int N = 4;

    bool isAllowed(int row, int column, bool allowedFields[][N])
    {
        return allowedFields[row][column];
    }

    int possiblePaths(int row, int column, bool allowedFields[][N])
    {
        if (!isAllowed(row, column, allowedFields))
            return 0;
        if (row == 0 || column == 0)
            return 1;
        return possiblePaths(row - 1, column, allowedFields) + possiblePaths(row, column - 1, allowedFields);
    }

    int possiblePaths(int n, bool allowedFields[][N])
    {
        // target field is (0,0), start field is (n-1, n-1).
        return possiblePaths(n - 1, n - 1, allowedFields);
    }
} // namespace follow_up

void testPaths()
{
    using namespace original;

    assert(possiblePaths(2) == 2);
    assert(possiblePaths(3) == 6);
    assert(possiblePaths(4) == 20);
}

void testPathsFollowUp()
{
    using namespace follow_up;

    bool allowedFields[4][4] = {{true, true, false, true}, {true, true, true, true}, {true, false, true, true}, {true, true, true, true}};

    assert(possiblePaths(4, allowedFields) == 8);
}

int main()
{
    testPaths();
    testPathsFollowUp();
}
