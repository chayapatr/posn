#include<iostream>
using namespace std;
int N, save[100];
void print(int n){
    if(n==0){
        for(int i=N;i;--i) cout << save[i] << " ";
        cout << endl; return;
    }
    for(int i=0;i<=1;++i){
        save[n] = i;
        print(n-1);
    }
}
int main(){
    cin >> N;
    print(N);
}