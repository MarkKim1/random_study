#include <iostream>
#include <vector>
using namespace std;
vector<int> vec;

void postorder(int leftindex, int endindex)
{
    if (leftindex > endindex)
    {
        return;
    }
    if (leftindex == endindex)
    {
        cout << vec[leftindex] << " ";
        return;
    }
    int rightindex = leftindex + 1;
    for (int i = leftindex; i <= endindex; i++)
    {
        if (vec[leftindex] < vec[i])
        {
            rightindex = i;
            break;
        }
    }
    postorder(leftindex + 1, rightindex - 1);
    postorder(rightindex, endindex);
    cout << vec[leftindex] << " ";
}

int main()
{
    int n;

    while (cin >> n)
    {
        vec.push_back(n);
    }
    postorder(0, vec.size() - 1);
}