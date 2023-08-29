#include <iostream>
#include <vector>

using namespace std;

int dfs(int n, vector<vector<int>>& computers) // computers의 주소 전달(원본 변경)
{
	if (computers[n][n] == 0) return 0; // 이미 방문했으면 0 반환
	
	computers[n][n] = 0; // 자기 자신을 0으로 변경

	for (int i = 0; i < computers.size(); i++)
	{
		if (computers[n][i] == 1)
		{
			dfs(i, computers);
		}
	}

	return 1;
}

int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;

	for (int i = 0; i < n; i++)
	{
		if (computers[i][i] && dfs(i, computers)) // 아직 방문하지 않았고, dfs로 연결된 모든 네트워크를 전부 탐색했을 경우
		{
			answer++;
		}
	}

	return answer;
}

int main()
{
	//vector<vector<int>> computers = { {1,1,0},{1,1,0},{0,0,1} };
	vector<vector<int>> computers = { {1,1,0},{1,1,1},{0,1,1} };

	cout << solution(computers.size(), computers) << endl;

	return 0;
}
