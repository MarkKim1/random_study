#include <iostream>
#include <unordered_map>
using namespace std;
int zero = 0;
int one = 0;
unordered_map<int, pair<int, int>> cache;
void fib(int n)
{
    if (cache.find(n) != cache.end())
    {
        zero += cache[n].first;
        one += cache[n].second;
        return;
    }

    if (n == 0)
    {
        zero++;
        return;
    }
    else if (n == 1)
    {
        one++;
        return;
    }
    fib(n - 1);
    fib(n - 2);
    cache[n] = {zero, one};
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int A;
        scanf("%d", &A);
        fib(A);
        cout << zero << " " << one << endl;
        zero = 0;
        one = 0;
        cache.clear();
    }
}