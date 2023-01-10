#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int H, W, N;
    for (int i = 0; i < T; i++)
    {
        cin >> H >> W >> N;
        int floor;
        int room;
        room = ceil(N / H);
        if (N % H == 0)
        {
            floor = H * 100;
            cout << floor + room << endl;
        }
        else
        {
            floor = (N % H) * 100;
            cout << floor + room + 1 << endl;
        }
    }
}