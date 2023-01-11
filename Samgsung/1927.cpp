#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<>> minheap;
    vector<int> result;
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int A;
        cin >> A;
        if (A == 0)
        {
            if (minheap.empty())
            {
                result.push_back(0);
            }
            else
            {
                result.push_back(minheap.top());
                minheap.pop();
            }
        }
        else
        {
            minheap.push(A);
        }
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }
    return 0;
}