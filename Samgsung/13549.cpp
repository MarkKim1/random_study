#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> dist(222222, 1e9);
    deque<int> dq;
    dq.push_back(N);
    dist[N] = 0;

    while (!dq.empty())
    {
        int curr = dq.front();
        dq.pop_front();
        if (curr == K)
        {
            cout << dist[curr] << "\n";
            break;
        }
        if (curr * 2 <= 200000 and dist[curr * 2] > dist[curr])
        {
            dist[curr * 2] = dist[curr];
            dq.push_front(curr * 2);
        }
        if (curr - 1 >= 0 and dist[curr - 1] > dist[curr] + 1)
        {
            dist[curr - 1] = dist[curr] + 1;
            dq.push_back(curr - 1);
        }
        if (curr + 1 >= 0 and dist[curr + 1] > dist[curr] + 1)
        {
            dist[curr + 1] = dist[curr] + 1;
            dq.push_back(curr + 1);
        }
    }
}