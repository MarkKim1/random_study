#include <iostream>
#include<climits>

using namespace std;

int miniDist(int distance[], bool Tset[]){
    int minimum = INT_MAX;
    int ind;
    for(int i = 0; i< 6; i++){
        if(Tset[i] == false and distance[i] <= minimum){
            minimum = distance[i];
            ind = i;
        }
    }
    return ind;
}

void DigstraAlgo(int graph[6][6], int src){
    int distance[6];
    bool Tset[6];

    for(int i = 0; i < 6; i++){
        distance[i] = INT_MAX;
        Tset[i] = false;
    }

    distance[src] = 0;

    for(int i = 0; i < 6; i++){
        int m = miniDist(distance,Tset);
        Tset[m] = true;
        for(int i = 0; i < 6; i++){
            if(!Tset[i] and graph[m][i] and distance[m] != INT_MAX and distance[m] + graph[m][i] < distance[i]){
                distance[i] = distance[m] + graph[m][i];
            }
        }
    }
        cout<<"Vertex\t\tDistance from source vertex"<<endl;
        for(int i = 0; i< 6; i++){
            char str = 65+i;
            cout << str << "  " << distance[i] << endl;
        }
}

int main () {
    int graph[6][6]={
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}};
        
        DigstraAlgo(graph,0);
        return 0;
}