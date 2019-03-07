#include<iostream>
using namespace std;

int memo[10000000];

int change(int i){
    if(i==0) return 0;
    if(i<0) return 1000000000;
    if(memo[i]!=-1) return memo[i];
    int ans = 1 + min(change(i-1), min(change(i-2),min(change(i-5), change(i-10))));
    memo[i] = ans;
    return ans;
}

int main(){
    for(int i=0;i<10000000;i++) memo[i] = -1;
    cout << change(13);
}