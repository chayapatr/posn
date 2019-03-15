#include<iostream>
using namespace std;
int a[4001] = {0};
int main(){
    int n; bool check=false;
    cin >> n;
    for(int i=0;i<n;++i){
        int input; cin >> input;
        a[input]++;
    }
    for(int i=0;i<=2017;i++){
        if(a[2017-i]==1) {
            cout << 2017 - i;
            check=true;
            break;
        } else if(a[2017+i]==1){
            cout << 2017 + i;
            check=true;
            break;
        }
    }
    if(!check) cout << -1;
}