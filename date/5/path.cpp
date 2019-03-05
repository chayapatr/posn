#include<iostream>
using namespace std;

int dp[4][6] = {-1};
char a[4][7] = {".....", ".#...", "...#.", "...#."};
int path(int i, int j){
    i=i-1;
    j=j-1;
    if(i<1 || j<1) return 0;
    if(a[i][j] == '#') return 0;
    if(i == 1 && j == 1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = path(i-1,j) + path(i,j-1);
}
int main(){
    cout << path(5,4);
    return 0;
}

