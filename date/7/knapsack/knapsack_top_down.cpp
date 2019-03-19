#include<iostream>
#include<cstring>
using namespace std;
int max(int a, int b){ return (a > b) ? a : b; }
int a[100][100];
int knapsack(int C, int n,int w[], int v[]){
    cout << C << " " << n << endl;
    if (C == 0 || n == 0) return 0;
    if (a[n][C]!=-1) return a[n][C];
    if (w[n-1] > C) return knapsack(C,n-1,w,v);
    else return a[n][C] = max(v[n-1]+knapsack(C-w[n-1],n-1,w,v),knapsack(C,n-1,w,v));
}
int main(){
    memset(a, -1, sizeof(a));
    int w[] = {10,20,30};
    int v[] = {60,100,30};
    int C = 50;
    int n = 3;
    cout << knapsack(C,n,w,v) << endl;
}
