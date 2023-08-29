#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool check_diff(string begin, string word) // 다른 알파벳이 하나만 있는지 체크
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
    queue<pair<string, int>> q;
    bool visited[51] = {0}; // 초기화
    
    q.push({ begin, 0 });
    
    while(!q.empty())
    {
        string word = q.front().first;
        int cnt = q.front().second;
        
        q.pop();
        
        if (word == target)
        {
            return cnt;
        }
        
        for (int i = 0; i < words.size(); i++)
        {
            if (visited[i] || !check_diff(word, words[i])) continue;
            
            q.push({ words[i], cnt+1 });
            visited[i] = true;
        }
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) 
{
    int answer = 0;
    auto it = find(words.begin(), words.end(), target);

    if (it != words.end())
    {
        answer = bfs(begin, target, words);
    }
    
    return answer;
}

int main()
{
	vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
	//vector<string> words = { "hot", "dot", "dog", "lot", "log" };
	
	string begin = "hit";
	string target = "cog";

	cout << solution(begin, target, words) << endl;

	return 0;
}
