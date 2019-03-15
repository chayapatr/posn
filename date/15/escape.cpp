#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
// int map[1005][1005];
// int dp[1005][1005];
// long long int path(int i, int j){
//     if (i == 0 && j == 0) return 1;
//     if (map[i][j] == 1) return 0;
//     if (dp[i][j] != -1) returnV dp[i][j];
//     if(i>0 && j>0) return dp[i][j] = path(i-1,j) + path(i,j-1);
//     else if(i>0) return dp[i][j] = path(i-1,j);
//     else return dp[i][j] = path(i,j-1);
// }
// int main(){
//     int n, m;
//     cin >> n >> m;
//     memset(map, -1, sizeof(map));
//     memset(dp, -1, sizeof(dp));
//     for(int i=0;i<n;i++) for(int j=0;j<m;j++)
//     cin >> map[i][j];
//     cout << path(n-1,m-1) << endl;
// }
using namespace std;
int keep[1005][1005];
int dp[1005][1005];
int main(){
    int N,M,i,j,a,b;

    cin >> N ;
    cin >> M;
    int C = (pow(10,9))+7;
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++){
            cin >> keep[i][j];
        }
    }
    dp[1][1]=1;
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++){
            dp[1][1]=1;
            if(keep[i][j] != 0){
                continue;
            }
            dp[i][j]=((dp[i-1][j]%C)+(dp[i][j-1] % C))%C;
        }
    }
//    for(i=1;i<=N;i++){
//        for(j=1;j<=N;j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }

    cout << dp[N][M] % C;
}