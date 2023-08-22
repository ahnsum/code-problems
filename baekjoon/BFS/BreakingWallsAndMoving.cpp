#include <iostream>
#include <queue>
#include <vector>

#define MAX 1001

using namespace std;

typedef pair<int, int> pos;
typedef pair<int, pos> ipos;

queue<ipos> q;

vector<pair<int, int>> wall;

int map[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;
int result = MAX;

void bfs()
{
	q.push({ 1, { 1,1 } });
	visit[1][1] = true;

	while (!q.empty())
	{
		int cnt = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;

		q.pop();

		if (x == N && y == M)
		{
			result = min(result, cnt);

			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
			if (visit[nx][ny]) continue;

			if (map[nx][ny] == 0)
			{
				visit[nx][ny] = true;
				q.push({ cnt + 1, { nx, ny } });
			}
		}
	}
}

void init_visit()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			visit[i][j] = false;
		}
	}
}

void wall_breaker() /// 시간초과!!!
{
	for (int i = 0; i < wall.size(); i++)
	{
		int x = wall[i].first;
		int y = wall[i].second;

		init_visit();

		map[x][y] = 0;
		bfs();
		map[x][y] = 1;
	}
}

void input()
{
	char ch;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> ch;

			map[i][j] = ch - '0';

			if (map[i][j] == 1)
			{
				wall.push_back({ i, j });
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	input();

	bfs();

	wall_breaker();

	result = result == MAX ? -1 : result;

	cout << result << endl;

	return 0;
}
