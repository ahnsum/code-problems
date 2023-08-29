#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    answer.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        if (answer.back() == arr[i]) continue;

        answer.push_back(arr[i]);
    }

    return answer;
}

int main()
{
    vector<int> arr = { 1,1,3,3,0,1,1 };
    //vector<int> arr = { 4,4,4,3,3 };

    vector<int> result = solution(arr);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
