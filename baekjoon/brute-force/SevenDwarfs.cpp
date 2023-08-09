#include <iostream>
#include <algorithm>

using namespace std;

#define N 9
#define MAX 100

int Solution(int* arr, int sum)
{
	int find = sum - MAX;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (arr[i] + arr[j] == find)
			{
				arr[i] = 0;
				arr[j] = 0;

				return 0;
			}
		}
	}
}

int main()
{
	int array[9];
	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> array[i];
		sum += array[i];
	}

	Solution(array, sum);

	sort(array, array + N);

	for (int i = 2; i < N; i++)
	{
		cout << array[i] << endl;
	}

	return 0;
}
