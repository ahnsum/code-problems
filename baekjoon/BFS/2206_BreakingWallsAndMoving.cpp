#include <iostream>
#include <queue>
#include <vector>

#define MAX 1001

using namespace std;

typedef struct pos
{
	int x;
	int y;
	int wall;
};

queue<pos> q;

int map[MAX][MAX];
int visited[MAX][MAX][2]; // 벽 부숨 여부 체크

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;

int bfs()
{
	visited[1][1][0] = 1;
	q.push({ 1, 1, 0 });

	while (!q.empty())
	{
		pos cur = q.front();

		q.pop();

		if (cur.x == N && cur.y == M)
		{
			return visited[cur.x][cur.y][cur.wall];
		}

		for (int i = 0; i < 4; i++)
		{
			pos next;

			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];
			next.wall = cur.wall;
			
			if (next.x < 1 || next.y < 1 || next.x > N || next.y > M) continue;
			if (visited[next.x][next.y][cur.wall]) continue;

			if (map[next.x][next.y] == 0) // 벽이 없다면 이동
			{
				visited[next.x][next.y][next.wall] = visited[cur.x][cur.y][cur.wall] + 1;
				q.push({ next.x, next.y, cur.wall });
			}

			if (map[next.x][next.y] == 1 && next.wall == 0) // 벽 하나 부수기
			{
				visited[next.x][next.y][1] = visited[cur.x][cur.y][cur.wall] + 1;
				next.wall = 1;
				q.push(next);
			}
		}
	}

	return -1;
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
		}
	}
}

int main()
{
	cin >> N >> M;

	input();

	cout << bfs();

	return 0;
}
