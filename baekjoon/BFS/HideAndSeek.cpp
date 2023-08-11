
#include <iostream>
#include <queue>

using namespace std;

#define MAX(x, y) x > y ? x : y

queue<pair<int, int>> q;
bool visit[100001];
int N, K, result;

bool valid(int n)
{
	if (n < 0 || n > 100000 || visit[n])
	{
		return false;
	}
	return true;
}

void bfs(int n)
{
	q.push({ N,0 });
	visit[N] = 0;

	while (!q.empty())
	{
		int data = q.front().first;
		int depth = q.front().second;

		q.pop();

		if (data == K)
		{
			result = depth;
			break;
		}

		if (valid(data - 1)) // X - 1
		{
			visit[data - 1] = true;
			q.push({ data - 1, depth + 1 });
		}
		if (valid(data + 1)) // X + 1
		{
			visit[data + 1] = true;
			q.push({ data + 1, depth + 1 });
		}
		if (valid(data * 2)) // X * 2
		{
			visit[data * 2] = true;
			q.push({ data * 2, depth + 1 });
		}
	}
}

int main()
{
	cin >> N >> K;
	
	bfs(N);

	cout << result << endl;

	return 0;
}
