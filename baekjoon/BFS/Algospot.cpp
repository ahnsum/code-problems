#include <iostream>
#include <queue>

#define MAX 101

using namespace std;

typedef pair<int, int> dist;
typedef pair<int, dist> pdist;

priority_queue<pdist, vector<pdist>, greater<pdist>> pq;

int visit[MAX][MAX];
int pos[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs(int n, int m)
{
	int cnt = 0;
	pq.push({ 0, { 1,1 } });
	visit[1][1] = true;

	while (!pq.empty())
	{
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		int c = pq.top().first;

		pq.pop(); // pop 중요!

		if (x == m && y == n)
		{
			cnt = c;
			break;
		}

		for (int i = 0; i < 4; i++) // 상하좌우 탐색
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (visit[ny][nx]) // 이미 방문했을 경우
			{
				continue;
			}

			if (nx > 0 && ny > 0 && nx <= m && ny <= n) // 범위 벗어날 경우
			{
				visit[ny][nx] = true;

				if (pos[ny][nx] == 1) // 벽이 있을 경우
				{
					pq.push({ c + 1, {ny, nx} });
				}
				else // 벽이 없을 경우
				{
					pq.push({ c, {ny, nx} });
				}
			}
		}
	}

	return cnt;
}

int main()
{
	int N, M;
	char input;

	cin >> M >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> input;
			pos[i][j] = input - '0'; // 문자를 숫자로
		}
	}

	cout << bfs(N, M) << endl;
	
	return 0;
}
