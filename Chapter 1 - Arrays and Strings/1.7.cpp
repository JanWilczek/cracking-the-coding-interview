#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>


void printMatrix(int** image, int M, int N)
{
    std::for_each(image, image + M, [=](int* row){std::copy(row, row + N, std::ostream_iterator<int>{std::cout, "\t"}); std::cout << std::endl;});
}

void conditionalZero(int** matrix, int M, int N)
{
	std::vector<bool> rowsToZero(M);
	std::vector<bool> columnsToZero(N);

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!matrix[i][j])
			{
				rowsToZero[i] = true;
				columnsToZero[j] = true;
			}
		}
	}

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (rowsToZero[i] || columnsToZero[j])
			{
				matrix[i][j] = 0;
			}
		}
	}
}


int main()
{
    const int M = 3;
    const int N = 5;
    int matrix2[][N] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 13, 14};
    int** matrix = reinterpret_cast<int**>(matrix2);

    std::cout << "Before:\n";
    printMatrix(matrix, M, N);
    conditionalZero(matrix, M, N);
    std::cout << "After:\n";
    printMatrix(matrix, M, N);

    return 0;
}
