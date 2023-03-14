#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> nums(N + 1);
    for (int i = 1; i <= N; i++)
    {
        nums[i] = i;
    }
    for (int i = 2; i <= N; i++)
    {
        if (nums[i] == 0)
            continue;
        for (int j = i * 2; j <= N; j += i)
        {
            nums[j] = 0;
        }
    }
    vector<int> prime;
    for (int i = 1; i <= N; i++)
    {
        if (nums[i] != 0)
        {
            prime.push_back(nums[i]);
        }
    }
    int left = 1, curr = 0, cnt = 0;
    for (int i = 1; i < prime.size(); i++)
    {
        curr += prime[i];
        while (left < prime.size() and curr > N)
        {
            curr -= prime[left];
            left++;
        }
        if (curr == N)
        {
            cnt++;
        }
    }
    cout << cnt;
}