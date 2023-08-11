#include <iostream>

using namespace std;

#define MAX(x, y) x > y ? x : y

int main()
{
	int day[17] = { 0 };
	int cost[17] = { 0 };
	int salary[17] = { 0 };
	int next = 0;
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> day[i] >> cost[i];
	}

	for (int i = N; i > 0; i--)
	{
		next = i + day[i];

		if (next > N + 1)
		{
			salary[i] = salary[i + 1];
		}
		else
		{
			salary[i] = MAX(salary[i + 1], salary[next] + cost[i]);
		}
	}

	cout << salary[1] << endl;

	return 0;
}
