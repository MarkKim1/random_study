#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int k;
        cin >> k;
        priority_queue<pair<int, int>> maxheap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minheap;
        vector<bool> deleted(k, true);

        for (int i = 0; i < k; i++)
        {
            char A;
            int B;
            cin >> A >> B;
            if (A == 'I')
            {
                maxheap.push(make_pair(B, i));
                minheap.push(make_pair(B, i));
                deleted[i] = false;
            }
            else
            {
                if (B == -1)
                {
                    while (!minheap.empty() and deleted[minheap.top().second])
                    {
                        minheap.pop();
                    }
                    if (!minheap.empty())
                    {
                        deleted[minheap.top().second] = true;
                        minheap.pop();
                    }
                }
                else if (B == 1)
                {
                    while (!maxheap.empty() and deleted[maxheap.top().second])
                    {
                        maxheap.pop();
                    }
                    if (!maxheap.empty())
                    {
                        deleted[maxheap.top().second] = true;
                        maxheap.pop();
                    }
                }
            }
        }
        while (!minheap.empty() and deleted[minheap.top().second])
        {
            minheap.pop();
        }
        while (!maxheap.empty() and deleted[maxheap.top().second])
        {
            maxheap.pop();
        }
        if (minheap.empty() and maxheap.empty())
        {
            cout << "EMPTY" << endl;
        }
        else
        {
            cout << maxheap.top().first << " " << minheap.top().first << endl;
        }
    }
}