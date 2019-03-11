#include<iostream>
using namespace std;
int main(){
    int h[3], n, q=0;
    cin >> n >> h[0] >> h[1] >> h[2];
    for(int i=0 ; i<n ; ++i){
        int a = h[(q+1)%3] > h[q] ? (h[(q+1)%3]-h[q]) : 100000000;
        int b = h[(q+2)%3] > h[q] ? (h[(q+2)%3]-h[q]) : 100000000;
        if(a != 100000000 || b != 100000000)
        h[i%3] = h[i%3] + 2*min(a,b);
        ++q%=3;
        cout << a << " " << b << endl;
        // cout <<"at time = " << i << " " << h[0] << " " << h[1] << " " << h[2] << endl;
    }
    cout << h[0] << " " << h[1] << " " << h[2];
}