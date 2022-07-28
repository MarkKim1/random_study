
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > matrix;
ll N,B;
matrix operator * (matrix& a, matrix& b){
    matrix c(N,vector<ll>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= 1000;
        }
    }
    return c;
}

matrix power(matrix a, ll B){
    matrix result(N,vector<ll>(N));
    for(int i = 0; i < result.size(); i++){
        result[i][i] = 1;
    }
    while(B > 0){
        if(B%2 == 1){
            result = a*result;
        }
        B/=2;
        a = a*a;
    }
    return result;
}

void PrintMatrix(const matrix& a){
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> B;
    matrix a(N,vector<ll>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }
    PrintMatrix(power(a,B));
    return 0;
}