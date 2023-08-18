#include <iostream>
#include <queue>
#include <vector>

#define MAX 8

using namespace std;

queue<pair<int, int>> q;

int map[MAX][MAX];
int tmp[MAX][MAX];
int visit[MAX][MAX] = { 0 };

vector<pair<int, int>> virus, space;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;
int result = 0;

void copyMap() // 맵 복사
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			tmp[i][j] = map[i][j];
		}
	}
}

void countMaxSpace() // 빈 칸 영역의 최대 크기
{
	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = 0;

			if (tmp[i][j] == 0)
			{
				cnt++;
			}
		}
	}

	result = max(result, cnt);
}

void bfs(int n, int m)
{
	q.push({ n, m });
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue; // 맵의 범위 안에 있는지 체크

			if (tmp[nx][ny] == 0) // 빈 칸이면 바이러스 감염
			{
				tmp[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
	}
}

void spreadVirus() // 바이러스 퍼뜨리기
{
	for (int i = 0; i < virus.size(); i++)
	{
		bfs(virus[i].first, virus[i].second);
	}

	countMaxSpace();
}

void wall(int cnt) // 벽 세우기
{
	if (cnt == 3)
	{
		spreadVirus();

		return;
	}

	for (int i = 0; i < space.size(); i++)
	{
		int x = space[i].first;
		int y = space[i].second;

		tmp[x][y] = 1;
		wall(cnt + 1);
		tmp[x][y] = 0;
	}
}

void wallMaker()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				copyMap(); // 맵 초기화
				
				tmp[i][j] = 1;
				wall(1);
				tmp[i][j] = 0;
			}
		}
	}
}

void input()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 0) // 빈 칸 좌표 저장
			{
				space.push_back({ i,j });
			}

			if (map[i][j] == 2) // 바이러스 좌표 저장
			{
				virus.push_back({ i,j });
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	input();

	wallMaker();

	cout << result << endl;

	return 0;
}
