#include <vector>

using namespace std;

int dfs(vector<vector<int>>& computers, int n)
{  
    if (!computers[n][n]) return 0;
    
    computers[n][n] = 0;
    
    for (int i = 0; i < computers.size(); i++)
    {
        if (computers[n][i])
        {
            dfs(computers, i);
        }
    }
    
    return 1;
}

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (computers[i][i] && dfs(computers, i))
        {
            answer++;
        }
    }
    
    return answer;
}
