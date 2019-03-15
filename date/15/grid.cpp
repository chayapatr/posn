#include<iostream>
using namespace std;
int dp[4][5];
char map[4][5] ={
{0,0,0,0,0},
{0,1,0,0,0},
{0,0,0,1,0},
{0,0,0,1,0}};

int path(int  i, int j){
    if (i == 0 || j == 0) return 1;
    if (map[i][j] == 1) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = path(i-1,j) + path(i,j-1);
}

int main(){
    memset(dp, -1, sizeof(dp));
    cout << path(3, 4);
}