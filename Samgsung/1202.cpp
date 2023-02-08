#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    priority_queue<int> pq;
    pair<int, int> INFO[N];
    int bags[K];
    for (int i = 0; i < N; i++)
    {
        cin >> INFO[i].first >> INFO[i].second;
    }
    for (int i = 0; i < K; i++)
    {
        cin >> bags[i];
    }
    sort(INFO, INFO + N);
    sort(bags, bags + K);
    int index = 0;
    long long result = 0;
    for (int i = 0; i < K; i++)
    {
        while (index < N and INFO[index].first <= bags[i])
        {
            pq.push(INFO[index++].second);
        }
        if (!pq.empty())
        {
            result += pq.top();
            pq.pop();
        }
    }
    cout << result << "\n";
}