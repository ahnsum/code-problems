#include <iostream>
#include <queue>

#define MAX 1001

using namespace std;

queue<pair<pair<int, int>, int>> q;
bool visit[MAX][MAX];

bool valid(int dis, int clip)
{
	return (visit[dis][clip]) ? false : true;
}

int bfs(int num)
{
	q.push({ { 1, 0 }, 0 });
	visit[1][0] = 0;
	
	while (!q.empty())
	{
		int currentDis = q.front().first.first;
		int currentClip = q.front().first.second;
		int currentTime = q.front().second;

		q.pop();

		if (currentDis == num)
		{
			return currentTime;
		}

		if (currentDis > 0 && currentDis < MAX)
		{
			if (valid(currentDis, currentDis)) // 클립보드에 복사
			{
				q.push({ { currentDis, currentDis }, currentTime + 1 });
				visit[currentDis][currentDis] = true;
			}
			if (valid(currentDis - 1, currentClip)) // 화면에서 하나 삭제
			{
				q.push({ { currentDis - 1, currentClip }, currentTime + 1 });
				visit[currentDis - 1][currentClip] = true;
			}
		}
		if (currentClip > 0 && (currentDis + currentClip) < MAX)
		{
			if (valid(currentDis + currentClip, currentClip)) // 화면에 클립보드 붙여넣기
			{
				q.push({ { currentDis + currentClip, currentClip }, currentTime + 1 });
				visit[currentDis + currentClip][currentClip] = true;
			}
		}
	}

	return 0;
}

int main()
{
	int S;

	cin >> S;

	cout << bfs(S) << endl;

	return 0;
}
