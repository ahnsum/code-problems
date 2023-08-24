#include <vector>
#include <queue>

#define MAX 100

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int bfs(vector<vector<int>> maps)
{
    queue<pair<pair<int,int>, int>> q;
    bool visited[MAX][MAX] = {0};

    int N = maps.size();
    int M = maps[0].size();
    
    visited[0][0] = true;
    q.push({{0,0}, 1});
    
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        
        q.pop();
        
        if (x == N-1 && y == M-1)
        {
            return cnt;
        }
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (maps[nx][ny] == 0) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({{nx, ny}, cnt + 1});
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
