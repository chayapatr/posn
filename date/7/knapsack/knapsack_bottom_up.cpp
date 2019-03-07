#include<iostream>
#include<cstring>
using namespace std;
int max(int a, int b){ return (a > b) ? a : b; }
int knapsack(int C, int N, int  w[], int v[]){
    int K[C+1][N+1];
        for(int n=0;n<=N;n++){
            for(int c=0;c<=C;c++){
                if (n == 0 && c == 0) K[c][n] = 0;
                else if (w[n-1] <= c) K[c][n] = max(v[n-1] + K[c-w[n-1]][n-1], K[c][n-1]);
                else K[c][n] = K[c][n-1];
                cout << c << " " << n << " " << K[c][n] << endl;
            }
    }
    return K[C][N];
}
int main(){
    int w[] = {10,20,30};
    int v[] = {60,100,30};
    int C = 50;
    int n = 3;
    cout << knapsack(C,n,w,v);
}