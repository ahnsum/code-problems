#include <iostream>

using namespace std;

int main()
{
	int arr[100];
	int n, m;
	int result = 0;
	int sum = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				sum = arr[i] + arr[j] + arr[k];

				result = (sum > result && sum <= m) ? sum : result;
			}
		}
	}

	cout << result;
}
