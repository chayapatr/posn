#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
#include<stdio.h>
// #include <time.h>
using namespace std;
double length(pair<double, double> a, pair<double, double> b){
    return sqrt(pow((a.first - b.first),2) + pow((a.second-b.second),2));
}
int main(){
    int num;
    cin >> num;
    vector<pair<double, double> > coor,node[num];
    bool visited[num];
    double l=0;
    for(int i=0;i<num;i++){
        double x,y; cin >> x >> y;
        coor.push_back({x,y});
    }
    clock_t tStart = clock();
    for(int i=0;i<num;i++) for(int j=i;j<num;j++)
        if(i!=j) node[i].push_back({length(coor[i],coor[j]), j});
    priority_queue<pair<double, double> > PQ;
    PQ.push({0,0});
    while(!PQ.empty()){
        double u = -PQ.top().first; int v = PQ.top().second;
        PQ.pop();
        if(visited[v]) continue;
        for(int i=0;i<node[v].size();i++) PQ.push({-node[v][i].first,node[v][i].second});
        l+=u;
        visited[v] = true;
    }
    printf("%.2lf", l);
    // printf("\nTime taken: %lfs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}