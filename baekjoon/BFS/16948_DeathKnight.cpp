#include <iostream>
#include <queue>

#define MAX 201

using namespace std;

typedef pair<int, int> pos;
typedef pair<int, pos> ipos;

queue<ipos> q;

int visit[MAX][MAX];

int N;
int r1, r2, c1, c2;

bool valid(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N || visit[x][y])
	{
		return false;
	}

	return true;
}

void push_pos(int cnt, int x, int y)
{
	if (valid(x, y))
	{
		visit[x][y] = true;
		q.push({ cnt + 1, {x, y} });
	}
}

int bfs()
{
	q.push({ 0, {r1, c1} });
	visit[r1][c1] = true;

	while (!q.empty())
	{
		int cnt = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;

		q.pop();

		if (x == r2 && y == c2)
		{
			return cnt;
		}

		push_pos(cnt, x - 2, y - 1);
		push_pos(cnt, x - 2, y + 1);
		push_pos(cnt, x, y - 2);
		push_pos(cnt, x, y + 2);
		push_pos(cnt, x + 2, y - 1);
		push_pos(cnt, x + 2, y + 1);
	}

	return -1;
}

int main()
{
	cin >> N;
	cin >> r1 >> c1 >> r2 >> c2;

	cout << bfs() << endl;

	return 0;
}
