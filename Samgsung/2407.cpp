#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string cache[101][101];

string add(string num1, string num2)
{
    string result = "";
    int size = max(num1.size(), num2.size());
    int num = 0;
    for (int i = 0; i < size || num; i++)
    {
        if (num1.size() > i)
            num += num1[i] - '0';
        if (num2.size() > i)
            num += num2[i] - '0';
        result += num % 10 + '0';
        num /= 10;
    }
    return result;
}

string combination(int n, int m)
{
    if (n == m || m == 0)
        return "1";
    string &result = cache[n][m];

    if (result != "")
    {
        return result;
    }
    result = add(combination(n - 1, m - 1), combination(n - 1, m));

    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    string result = combination(n, m);
    reverse(result.begin(), result.end());
    cout << result << "\n";
}