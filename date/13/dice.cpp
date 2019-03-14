#include<iostream>
using namespace std;
int res[1000];
int N;
void dice(int n){
    if(n==0){
        for(int i=N;i;--i) cout << res[i] << " ";
        cout << endl;
        return;
    }
    for(int i=1;i<=6;++i) {
        res[n] = i;
        dice(n-1);
    }
}
int main(){
    cin >> N;
    dice(N);
}