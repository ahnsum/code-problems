#include <iostream>
#include <queue>

#define MAX 101

using namespace std;

queue<pair<int, int>> q;

char drawing[MAX][MAX];
int visit[MAX][MAX] = { 0 };

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N, nb, b;

void bfs(int i, int j)
{
	q.push({ i,j });
	visit[i][j] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (visit[nx][ny]) continue;
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			
			if (drawing[x][y] == drawing[nx][ny])
			{
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

void non_blind()
{
	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j]) continue;

			bfs(i, j);

			cnt++;
		}
	}

	nb = cnt;
}

void blind()
{
	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = false;

			if (drawing[i][j] == 'G')
			{
				drawing[i][j] = 'R';
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j]) continue;

			bfs(i, j);

			cnt++;
		}
	}

	b = cnt;
}

void input()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> drawing[i][j];
		}
	}
}

int main()
{
	cin >> N;

	input();

	non_blind();
	blind();

	cout << nb << ' ' << b << endl;

	return 0;
}
