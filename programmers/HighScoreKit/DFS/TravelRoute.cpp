#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool visited[10001] = { 0 };
bool check = false;
vector<string> path;
int cnt = 0;

void dfs(vector<vector<string>> tickets, string cur)
{
    path.push_back(cur);

    if (cnt == tickets.size())
    {
        check = true;
    }

    for (int i = 0; i < tickets.size(); i++)
    {
        if (visited[i]) continue;

        if (cur == tickets[i][0])
        {
            visited[i] = true;
            cnt++;
            dfs(tickets, tickets[i][1]);

            if (!check) // 공항을 다 돌지 못하고 경로가 끊긴 경우
            {
                path.pop_back();
                visited[i] = false;
            }
        }
    }
}

int main()
{
    //vector<vector<string>> tickets = { {"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"} };
    vector<vector<string>> tickets = { {"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"} };
    
    sort(tickets.begin(), tickets.end()); // 알파벳 순서 정렬
    
    dfs(tickets, "ICN"); // "ICN"을 기준으로 시작

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }

    return 0;
}
