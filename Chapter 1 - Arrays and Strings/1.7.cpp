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
    constexpr int M = 3;
    constexpr int N = 5;
    int** matrix = new int*[M];
	for (int i = 0; i < M; ++i)
	{
		matrix[i] = new int[N]{N*i + 0, N*i + 1, N*i + 2, N*i + 3, N*i + 4};
	}
	matrix[1][2] = 0;

    std::cout << "Before:\n";
    printMatrix(matrix, M, N);
    conditionalZero(matrix, M, N);
    std::cout << "After:\n";
    printMatrix(matrix, M, N);

	for (int i = 0; i < M; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

    return 0;
}
