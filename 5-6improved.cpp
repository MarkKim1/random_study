#include <iostream>
#include <vector>
#include<limits>
using namespace std;

double BuyAndSellStockOnce(const vector<int> &prices){
    double min_price_so_far = numeric_limits<double>::infinity(),max_profit = 0;
    for(double price : prices){
        double max_profit_sell_today = price - min_price_so_far;
            cout <<" max_profit_sell_today: " <<max_profit_sell_today << endl;
        max_profit = max(max_profit, max_profit_sell_today);
            cout <<" max_profit: " <<max_profit << endl;
        min_price_so_far = min(min_price_so_far, price);
    }
    return max_profit;
    //시간복잡도는 O(n)이고, 공간복잡도는 O(1)이다. 여기서 n은 배열의 길이를 말한다.
}

int main () {
    vector<int> a;
    int count = 0;
    int number = 0;
    cout << "how many numbers:";
    cin >> count;
    for(int i = 0; i < count; i++){
        cin >> number;
        a.push_back(number);
    }

    double result = BuyAndSellStockOnce(a);  
    cout <<"result: " <<result << endl;  
}