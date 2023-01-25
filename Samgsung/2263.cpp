#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> postorder;
vector<int> vec;
unordered_map<int, int> inorder;

void solve(int inorder_left, int inorder_right, int postorder_left, int postorder_right)
{
    if (inorder_left > inorder_right || postorder_left > postorder_right)
    {
        return;
    }
    cout << (postorder[postorder_right]) << ' ';
    int mid = inorder[postorder[postorder_right]];
    int leftsize = mid - inorder_left;
    solve(inorder_left, mid - 1, postorder_left, postorder_left + leftsize - 1);
    solve(mid + 1, inorder_right, postorder_left + leftsize, postorder_right - 1);
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int A;
        cin >> A;
        inorder[A] = i;
    }
    for (int i = 0; i < T; i++)
    {
        int A;
        cin >> A;
        postorder.push_back(A);
    }
    int n = postorder.size();
    solve(0, n - 1, 0, n - 1);
}