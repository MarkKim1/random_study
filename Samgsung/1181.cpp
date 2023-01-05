// 단어 정렬
// https://www.acmicpc.net/problem/1181

#include <iostream>
#include <string>
#include <vector>

using namespace std;
void merge_solve(vector<string> &vec, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<string> L(n1);
    vector<string> M(n2);
    for (int i = 0; i < n1; i++)
    {
        L[i] = vec[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        M[j] = vec[mid + 1 + j];
    }
    int i, j, k;
    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i].size() < M[j].size())
        {
            vec[k] = L[i];
            i++;
        }
        else if (L[i].size() > M[j].size())
        {
            vec[k] = M[j];
            j++;
        }
        else
        {
            string a = min(L[i], M[j]);
            if (a == L[i])
            {
                vec[k] = a;
                i++;
            }
            else
            {
                vec[k] = M[j];
                j++;
            }
        }
        k++;
    }
    while (i < n1)
    {
        vec[k++] = L[i++];
    }
    while (j < n2)
    {
        vec[k++] = M[j++];
    }
}

void solve(vector<string> &vec, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        solve(vec, left, mid);
        solve(vec, mid + 1, right);
        merge_solve(vec, left, mid, right);
    }
}

int main()
{
    int T;
    vector<string> vec;
    string S;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> S;
        vec.push_back(S);
    }
    solve(vec, 0, vec.size() - 1);
    for (int i = 0; i < vec.size(); i++)
    {
        if (i - 1 >= 0 and vec[i] == vec[i - 1])
        {
            continue;
        }
        cout << vec[i] << endl;
    }

    return 0;
}