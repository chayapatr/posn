#include<iostream>
using namespace std;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);
    int time[1000030] = {0};
    int n, sum=0, maxsum=0;
    cin >> n;
    for(int i=0;i<n;i++){
        int in, out;
        cin >> in >> out;
        ++time[in];
        --time[out];
    }
    for(int i=0;i<1000000;++i){
        if(sum<0) sum = 0;
        sum+=time[i];
        if(sum>=maxsum) maxsum=sum;
    }
    cout << maxsum;
}