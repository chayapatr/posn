// note 12mar คีนบอกว่าถ้าติด toi จะตกวิทยาการคำนวณให้ดูรอบนึง
#include<iostream>
using namespace std;
int x[1000000], t, n;
int count(int input){
    int count = 0, y = 0, i;
    for(i = 0; i < n ; i++){
        if(y < x[i]){
            ++count;
            y = input - x[i];
        } else y = y - x[i];
    }
    return count;
}
int main(){
    int left = 0, right = 1e9, borderleft, save, mid, max = 0;
    cin >> n >> t;
    for(int i = 0; i < n ; i++) {
        cin >> x[i];
        if(x[i] >= max) max = x[i];
    }
    if(t == 1){
        cout << -1;
        return 0;
    }
    left = max;
    while(left < right){
        mid = (left + right) / 2;
        (count(mid) <= t) ? right = mid : left = mid + 1;
    }
    save = mid; right = 1e9;
    while(left < right){
        mid = (left + right) / 2;
        (count(mid) == t) ? left = mid + 1 : right = mid ;
    }
    cout << save << " " << mid;
}