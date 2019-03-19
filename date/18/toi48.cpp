#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;
int max(int a, int b){ return (a > b) ? a : b; }
long knapsack(long N, long C, long v[], long w[]){
    long dp[N+10][C+10];
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<=N;++i) {
        for(int j=0;j<=C;++j) {
            if(i==0||j==0) dp[i][j] = 0;
            else if(w[i-1]<=j) dp[i][j] = max(v[i-1]+dp[i-1][j-w[i-1]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    return dp[N][C];
}
int main(){
    int number, max;
    long v[10000], w[10000];
    cin >> number >> max;
    for(int i=0;i<number;++i) cin >> v[i];
    for(int i=0;i<number;++i) {
        long temp;
        cin >> temp; w[i] = temp*8 + 8;
    }
    cout << knapsack(number, max, v, w);
}