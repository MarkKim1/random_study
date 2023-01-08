#include <iostream>
#include <vector>
using namespace std;
struct INFO
{
    int x;
    int y;
};

void merge_sort(int left, int mid, int right, vector<INFO> &vec)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    INFO M[n1];
    INFO N[n2];
    int i = 0; // n1
    int j = 0; // n2
    int k = left;
    for (int i = 0; i < n1; i++)
    {
        M[i] = vec[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        N[i] = vec[mid + 1 + i];
    }
    while (i < n1 and j < n2)
    {
        if (M[i].x < N[j].x)
        {
            vec[k] = M[i];
            i++;
        }
        else if (M[i].x > N[j].x)
        {
            vec[k] = N[j];
            j++;
        }
        else if (M[i].x == N[j].x)
        {
            if (M[i].y < N[j].y)
            {
                vec[k] = M[i];
                i++;
            }
            else
            {
                vec[k] = N[j];
                j++;
            }
        }
        k++;
    }
    while (i < n1)
    {
        vec[k++] = M[i++];
    }
    while (j < n2)
    {
        vec[k++] = N[j++];
    }
}

void merge(int left, int right, vector<INFO> &vec)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge(left, mid, vec);
        merge(mid + 1, right, vec);
        merge_sort(left, mid, right, vec);
    }
}
int main()
{
    int T;
    cin >> T;
    vector<INFO> vec;
    for (int i = 0; i < T; i++)
    {
        int A, B;
        cin >> A >> B;
        vec.push_back({A, B});
    }
    merge(0, vec.size() - 1, vec);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i].x << " " << vec[i].y << "\n";
    }
}