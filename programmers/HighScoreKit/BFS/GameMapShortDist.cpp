#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pair<pair<int, int>, int>> q;
bool visited[100][100] = { 0 };

int bfs(vector<vector<int>> maps)
{
	int N = maps.size();
	int M = maps[0].size();

	q.push({ {0, 0}, 1 });
	visited[0][0] = true;

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;

		q.pop();

		if (x == N - 1 && y == M - 1)
		{
			return cnt;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny]) continue;
			if (maps[nx][ny] == 0) continue;

			visited[nx][ny] = true;
			q.push({{ nx, ny }, cnt + 1});
		}
	}

	return -1;
}

int solution(vector<vector<int>> maps)
{
	int answer = 0;

	answer = bfs(maps);

	return answer;
}

int main()
{
	vector<vector<int>> maps = { {1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1} };
	//vector<vector<int>> maps = { {1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1} };
	
	cout << solution(maps) << endl;

	return 0;
}
