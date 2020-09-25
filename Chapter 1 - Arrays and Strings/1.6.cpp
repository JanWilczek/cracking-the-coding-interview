#include <iostream>
#include <iterator>
#include <algorithm>

void rotate90(int** image, int N)
{
	if (!image) return;
	
	int iRange = N / 2;
    int jRange = N / 2;
	if (N % 2 != 0)
	{
		iRange += 1;
    }
	
	int temp;

	for (int i = 0; i < iRange; ++i)
	{
		for (int j = 0; j < jRange; ++j)
		{
			// (0,0) -> (0,N-1) -> (N-1,N-1) -> (N-1,0)
			// (i,j) -> (j, N-i-1) -> (N-i-1,N-j-1) -> (N-j-1,i)
			// N = 10; (2,3) -> (3,7) -> (7,6) -> (6,2)
			// N = 5; (2,1) -> (1,2) -> (2,3) -> (3,2)
			temp = image[i][j];
			image[i][j] = image[N-j-1][i];
			image[N-j-1][i] = image[N-i-1][N-j-1];
			image[N-i-1][N-j-1] = image[j][N-i-1];
			image[j][N-i-1] = temp;
		}
	}
}

void printImage2(int** image, int N)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cout << image[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

void printImage(int** image, int N)
{
    std::for_each(image, image + N, [=](int* row){std::copy(row, row + N, std::ostream_iterator<int>{std::cout, "\t"}); std::cout << std::endl;});
}

int main()
{
    constexpr int N = 5;
    int** image = new int*[N];
    for (int i = 0; i < N; ++i)
    {
        image[i] = new int[N];
        for (int j = 0; j < N; ++j)
        {
            image[i][j] = N*i + j + 1;
        }
    }

    std::cout << "Before:" << std::endl;
    printImage(image, N);
    rotate90(image, N);
    std::cout << "After:" << std::endl;
    printImage(image, N);

    for (int i = 0; i < N; ++i)
    {
        delete[] image[i];
    }
    delete[] image;
}
