#include<iostream>
#include<math.h>
using namespace std;
long long int cat[100000];
int n, j; bool first;
long long int check(long long int x){
    first = false;
    for(int i=0;i<n;i++){
        if(cat[i] <= x) continue;
        if(cat[i] != cat[j] && first) return false;
        first = !first; j = i;
    }
    return true;
}
int main(){
    long long int left = 0, right = pow(2,31), mid;
    cin >> n;
    for(int i=0;i<n;i++) cin >> cat[i];
    while(left < right){
        mid = (left+right) / 2;
        check(mid) ? right = mid : left = mid+1;
    }
    cout << mid;
}