#include <iostream>
#include <queue>
#include <vector>

#define MAX 8

using namespace std;

queue<pair<int, int>> q;

int map[MAX][MAX]; // 입력
int tmp[MAX][MAX]; // 복사
int arr[MAX][MAX]; // 조합

vector<pair<int, int>> virus, space;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;
int result = 0;

void copyMap(int copyArr[MAX][MAX], int newArr[MAX][MAX]) // 맵 복사
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			copyArr[i][j] = newArr[i][j];
		}
	}
}

void countMaxSpace() // 안전 영역의 최대 크기
{
	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
			{
				cnt++;
			}
		}
	}

	result = max(result, cnt);
}

void bfs()
{
	copyMap(arr, tmp);

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (arr[nx][ny]) continue;
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue; // 맵의 범위 안에 있는지 체크

			// 빈 칸이면 바이러스 감염
			arr[nx][ny] = 2;
			q.push({ nx, ny });
		}
	}
}

void spreadVirus() // 바이러스 퍼뜨리기
{
	for (int i = 0; i < virus.size(); i++)
	{
		q.push({ virus[i].first, virus[i].second });
	}

	bfs();
}

void wall(int cnt) // 벽 세우기
{
	if (cnt == 3)
	{
		spreadVirus();
		countMaxSpace();

		return;
	}

	for (int i = 0; i < space.size(); i++) // 빈 칸을 벽 하나로 선택하고, 2개의 벽을 조합해나가는 방식
	{
		int x = space[i].first;
		int y = space[i].second;

		if (tmp[x][y] == 0)
		{
			tmp[x][y] = 1;
			wall(cnt + 1);
			tmp[x][y] = 0;
		}
	}
}

void wallMaker()
{
	for (int i = 0; i < space.size(); i++)
	{
		int x = space[i].first;
		int y = space[i].second;

		copyMap(tmp, map); // 맵 복사(초기화)

		tmp[x][y] = 1; // 빈 칸 하나를 벽으로 지정
		wall(1);
		tmp[x][y] = 0;
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
