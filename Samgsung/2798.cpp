#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    int result = 0;
    vector<int> vec(N);
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                int curr = vec[i] + vec[j] + vec[k];
                if (curr <= M)
                {
                    if (curr > result)
                    {
                        result = curr;
                    }
                }
            }
        }
    }
    cout << result << endl;
}