#include<iostream>
using namespace std;
int p[170];
int main(){
    int from, to, x=0;
    cin.tie(0); cin.sync_with_stdio(false);
    for(int i=2;i<=1000;i++){
        bool prime = true;
        for(int j=2; j*j <= i; j++) if(i%j==0){
            prime = false; break;
        }
        if(prime){
            p[x] = i*i; x++;
        }
    }
    cin >> from >> to;
    bool chk = false;
    for(int i=0;i<=200;i++){
        if(p[i] >= from && p[i] <= to) {
            cout << p[i] << " ";
            chk = true;
        }
        if(p[i+1] > to) break;
    }
    if(!chk) cout << -1;
}