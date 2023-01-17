#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    priority_queue<int> maxheap;
    for (int i = 0; i < T; i++)
    {
        int A;
        cin >> A;
        if (A == 0)
        {
            if (maxheap.empty())
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << maxheap.top() << "\n";
                maxheap.pop();
            }
        }
        else
        {
            maxheap.push(A);
        }
    }
}
