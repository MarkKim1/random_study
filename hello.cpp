#include <iostream>

using namespace std;

class Solution{
    public:
    void getsize(int arr[]){
        int size = sizeof(arr) / sizeof(arr[0]);
        cout << "getsize: " << size << endl;
    }
};

int main () {
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << size << endl;

    Solution *a = new Solution();
    a->getsize(arr);
}