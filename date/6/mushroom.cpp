#include<iostream>
#include<queue>
using namespace std;
int check(int i, int j){
    if(true){}
}
int main(){
    int col, sec=1, i=0, j=0;
    cin >> col;
    int map[col][2];
    long long res=0;
    bool visited[col][2];
    for(int i=0;i<2;i++) for(int j=0;j<col;j++)  visited[j][i] = false;
    for(int i=0;i<2;i++) for(int j=0;i<col;i++) cin >> map[j][i];
    visited[i][j] = true;
    while(sec<col*2){
        check(i, j);
        res+=map[i][j]*sec;
        sec++;
    }
}