#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;
string N;
int K;
int ans = 0;
void solve()
{
    queue<string> q;
    q.push(N);
    int curr_k = 0;
    int M = N.size();
    while (!q.empty() and curr_k < K)
    {
        int size = q.size();
        set<string> st;
        for (int a = 0; a < size; a++)
        {
            string curr = q.front();
            q.pop();

            for (int i = 0; i < M - 1; i++)
            {
                for (int j = i + 1; j < M; j++)
                {
                    if (i == 0 and N[j] == '0')
                    {
                        continue;
                    }
                    swap(curr[i], curr[j]);
                    if (st.find(curr) == st.end())
                    {
                        if (curr_k == K - 1 and ans < stoi(curr))
                        {
                            ans = stoi(curr);
                        }
                        st.insert(curr);
                        q.push(curr);
                    }
                    swap(curr[i], curr[j]);
                }
            }
        }
        curr_k++;
    }
}

int main()
{
    cin >> N >> K;
    if (N.size() == 1 || N.size() == 2 and stoi(N) % 10 == 0)
    {
        cout << -1 << "\n";
    }
    else
    {
        solve();
        cout << ans << "\n";
    }
}