#include <iostream>
#include <queue>

#define MAX 100001

using namespace std;

queue<pair<int, int>> q;
int N, K, result;
int pos[MAX] = { 0 };
bool visit[MAX];
vector<int> path;

bool valid(int n)
{
	if (n < 0 || n > MAX || visit[n])
	{
		return false;
	}
	return true;
}

void bfs()
{
	q.push({ N, 0 });
	visit[N] = 0;

	while (!q.empty())
	{
		int data = q.front().first;
		int depth = q.front().second;

		q.pop();

		if (data == K)
		{
			int index = data; // K (끝)
			while (index != N)
			{
				path.push_back(index);
				index = pos[index]; // 움직였던 시간과 위치 역순으로 저장
			}
			path.push_back(N); // N (시작)

			result = depth;
			break;
		}

		if (valid(data + 1))
		{
			visit[data + 1] = true;
			q.push({ data + 1, depth + 1 });
			pos[data + 1] = data;
		}
		if (valid(data - 1))
		{
			visit[data - 1] = true;
			q.push({ data - 1, depth + 1 });
			pos[data - 1] = data;
		}
		if (valid(data * 2))
		{
			visit[data * 2] = true;
			q.push({ data * 2, depth + 1 });
			pos[data * 2] = data;
		}
	}
}

void print_path()
{
	for (int i = path.size() - 1; i >= 0; i--)
	{
		cout << path[i] << " ";
	}
}

int main()
{
	cin >> N >> K;

	bfs();

	cout << result << endl;

	print_path();

	return 0;
}
