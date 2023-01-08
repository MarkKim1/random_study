#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<int> vec;
    for (int i = 0; i < T; i++)
    {
        string S;
        cin >> S;
        if (S == "push_front")
        {
            int A;
            cin >> A;
            vector<int> temp;
            temp.push_back(A);
            for (int i = 0; i < vec.size(); i++)
            {
                temp.push_back(vec[i]);
            }
            vec = temp;
        }
        if (S == "push_back")
        {
            int A;
            cin >> A;
            vec.push_back(A);
        }
        if (S == "pop_front")
        {
            if (vec.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                int front = vec[0];
                vector<int> temp(vec.size() - 1);
                for (int i = 1; i < vec.size(); i++)
                {
                    temp[i - 1] = vec[i];
                }
                vec = temp;
                cout << front << endl;
            }
        }
        if (S == "pop_back")
        {
            if (vec.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                int back = vec[vec.size() - 1];
                vector<int> temp(vec.size() - 1);
                for (int i = 0; i < vec.size() - 1; i++)
                {
                    temp[i] = vec[i];
                }
                vec = temp;
                cout << back << endl;
            }
        }
        if (S == "size")
        {
            cout << vec.size() << endl;
        }
        if (S == "empty")
        {
            if (vec.empty())
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        if (S == "front")
        {
            if (vec.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << vec.front() << endl;
            }
        }
        if (S == "back")
        {
            if (vec.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << vec.back() << endl;
            }
        }
    }
}