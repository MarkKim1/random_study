#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
unordered_map<char, pair<char, char>> map;
string curr;
void preorder(char curr_node)
{
    if (curr_node == '.')
    {
        return;
    }
    curr.push_back(curr_node);
    preorder(map[curr_node].first);
    preorder(map[curr_node].second);
}
void inorder(char curr_node)
{
    if (curr_node == '.')
    {
        return;
    }
    inorder(map[curr_node].first);
    curr.push_back(curr_node);
    inorder(map[curr_node].second);
}
void postorder(char curr_node)
{
    if (curr_node == '.')
    {
        return;
    }
    postorder(map[curr_node].first);
    postorder(map[curr_node].second);
    curr.push_back(curr_node);
}
int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        char from, left, right;
        cin >> from >> left >> right;
        map[from] = {left, right};
    }
    preorder('A');
    cout << curr << "\n";
    curr = "";
    inorder('A');
    cout << curr << "\n";
    curr = "";
    postorder('A');
    cout << curr << "\n";
    curr = "";
}