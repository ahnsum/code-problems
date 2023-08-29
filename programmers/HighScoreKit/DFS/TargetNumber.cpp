#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> numbers, int idx, int result, int target, int& answer)
{
	if (idx == numbers.size()) // numbers를 전부 돌았을 때
	{
		if (result == target) // target과 같다면
		{
			answer++;
		}
		return;
	}
	
	dfs(numbers, idx + 1, result + numbers[idx], target, answer);
	dfs(numbers, idx + 1, result - numbers[idx], target, answer);
}

int solution(vector<int> numbers, int target)
{
	int answer = 0;

	dfs(numbers, 0, 0, target, answer);

	return answer;
}

int main()
{
	vector<int> numbers = { 1, 1, 1, 1, 1 };
	//vector<int> numbers = { 4, 1, 2, 1 };

	int target = 3; 
	//int target = 4;

	cout << solution(numbers, target) << endl;

	return 0;
}
