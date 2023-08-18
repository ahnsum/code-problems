#include <iostream>
#include <queue>

#define MAX 100001

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool visit[MAX] = { 0 };
int N, K, result;

bool valid(int n)
{
	return (n < 0 || n > MAX || visit[n]) ? false : true;
}

void bfs()
{
	pq.push({ 0, N });
	visit[N] = 0;

	while (!pq.empty())
	{
		int currentTime = pq.top().first; // 경과 시간 기준으로 정렬(우선순위 큐)
		int currentPos = pq.top().second;

		pq.pop();

		if (currentPos == K)
		{
			result = currentTime;
			break;
		}

		if (valid(currentPos * 2))
		{
			pq.push({ currentTime, currentPos * 2 });
			visit[currentPos * 2] = true;
		}
		if (valid(currentPos + 1))
		{
			pq.push({ currentTime + 1, currentPos + 1 });
			visit[currentPos + 1] = true;
		}
		if (valid(currentPos - 1))
		{
			pq.push({ currentTime + 1, currentPos - 1 });
			visit[currentPos - 1] = true;
		}
	}
}

int main()
{
	cin >> N >> K;

	bfs();

	cout << result << endl;

	return 0;
}
