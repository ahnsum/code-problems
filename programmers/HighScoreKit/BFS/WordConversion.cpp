#include <string>
#include <vector>
#include <queue>

using namespace std;

bool check_diff(string begin, string word)
{
    int cnt = 0;
    int len = word.size();
    
    for (int i = 0; i < len; i++)
    {
        if (begin[i] == word[i])
        {
            cnt++;
        }
    }
    
    return cnt == len-1 ? true : false;
}

int bfs(string begin, string target, vector<string> words)
{
    int answer = 100;
    queue<pair<string, int>> q;
    bool visited[51] = {0};
    
    q.push({begin, 0});
    
    while(!q.empty())
    {
        string word = q.front().first;
        int cnt = q.front().second;
        
        q.pop();
        
        if (word == target)
        {
            answer = min(answer, cnt);
        }
        
        for (int i = 0; i < words.size(); i++)
        {
            if (visited[i] || !check_diff(word, words[i])) continue;
            
            q.push({words[i], cnt+1});
            visited[i] = true;
        }
    }
    
    return answer;
}

int solution(string begin, string target, vector<string> words) 
{
    int answer = 0;
    
    answer = bfs(begin, target, words);
    
    answer = (answer == 100) ? 0 : answer;
    
    return answer;
}
