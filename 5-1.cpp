#include <iostream>
#include <vector>

using namespace std;

void DutchFlagPartition(int pivot_index, vector<int> *A_ptr){
    vector<int>& A = *A_ptr;
    int pivot = A[pivot_index];
    int smaller = 0, equal = 0, larger = A.size();

    while(equal < larger) {
        if(A[equal] < pivot){
            swap(A[smaller++],A[equal++]);
            //cout << equal << endl;
        }
        else if(A[equal] == pivot){
            ++equal;
            //cout << equal << endl;
        }
        else{
            swap(A[equal],A[--larger]);
            //cout << "larger: " <<larger << endl;
        }
        
    }
}

int main () {
    vector<int> a;
    int arrayNumber;
    int value;
    cout << "ARRAY NUMBER: ";
    cin >> arrayNumber;

    for(int i = 0; i < arrayNumber; i++){
        cin >> value;
        a.push_back(value);
    }
    DutchFlagPartition((a.size()-1) / 2, &a);
    for(int i = 0; i < a.size(); i++){
        cout << a.at(i) << " ";
    }
    cout << endl;

    return 0;


}