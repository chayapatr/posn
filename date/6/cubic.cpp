#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long i,j,k,N,X;
    long long dp[10000];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    X=10000;
    for(i=1;i<=X;i++){
        if(i*i*i>X) break;
        for(j=i*i*i;j<X;j++) dp[j]=dp[j]+dp[j-(i*i*i)];
    }
    while(scanf("%d",&N)!=EOF) cout << dp[N] << endl;
}