#include<iostream>
using namespace std;
int a[10] = {0};
int main(){
    int p,max=0,cur=0;
    cin >> p;
    for(int i=0;i<p;i++){
        int in,out;
        cin >> in >> out;
        a[in-1]++;
        a[out]--;
    }
    for(int i=0;i<10;i++){
        cur = cur + a[i];
        if(cur >= max) max = cur;
    }
    cout << max;
}