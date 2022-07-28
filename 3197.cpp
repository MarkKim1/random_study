#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};


char lake[1501][1501];
int main () {
    int R,C;
    queue<pair<int,int> > nearWater;
    queue<pair<int,int> > target1;
    queue<pair<int,int> > target2;
    queue<pair<int,int> > dotPos;
    cin >> R >> C;
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> lake[i][j];
            if(lake[i][j] == '.'){
                dotPos.push(make_pair(i,j));
            }
            if(lake[i][j] == 'L'){
                dotPos.push(make_pair(i,j));
                if(!target1.empty()){
                    target2.push(make_pair(i,j));
                } target1.push(make_pair(i,j));
                lake[i][j] = '.';
            }
        }
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(lake[i][j] == 'X'){
                for(int n = 0; n < 4; n++){
                    if(lake[i + dx[n]][j+dy[n]] == '.'){
                        nearWater.push(make_pair(i,j));
                        lake[i][j] = '.';
                    }
                }
            }
        }
    }
    int count = 0;
    bool visited[1501][1501];
    nearWater.push(make_pair(target1.front().first,target1.front().second));
    while(!nearWater.empty()){
        if(nearWater.front().first == target1.front().first and nearWater.front().second == target1.front().second){
            count++;
            nearWater.pop();
            if(!nearWater.empty()){
                nearWater.push(make_pair(target1.front().first,target1.front().second));
            }
        }
        int currX = nearWater.front().first;
        int currY = nearWater.front().second;
        nearWater.pop();
        for(int n = 0; n < 4; n++){
            if(lake[currX + dx[n]][currY+dy[n]] == 'X'){
                nearWater.push(make_pair(currX + dx[n],currY + dy[n]));
            }
            
        }

    }


}