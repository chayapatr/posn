#include <iostream>
using namespace std;
int keep[1000005];
int N,T,i,j,k,leftt = 0, rightt = 1e9 ,mid,maxx = 0,leftt1 = 0, rightt1 = 1e9;
int findcharge(int y){
    int count = 0;
    int full = y;
    y = 0;
    for(i=0;i<N;i++){
        if(keep[i] > y){
            // cout << keep[i] << " " << y << endl;
            y = full - keep[i];
            count++;
        }
        else{
            y = y - keep[i];
        }
    }
    return count;
}
bool chk(int x){
    if(findcharge(x) > T){
        return false;
    }
    else{
        return true;
    }
}
bool chk1(int x){
    return findcharge(x) == T;
}

int main(){
    cin >> N >> T;
    for(i=0;i<N;i++){
        cin >> keep[i];
        if(keep[i] > maxx){
            maxx = keep[i];
        }
    }
    if( T == 1){
        cout << "-1";
        return 0;
    }
    leftt = maxx;
    while(leftt < rightt){
        mid = (leftt + rightt) /2;
        if(chk(mid) == false){
            leftt = mid+1;
        }
        else{
            rightt = mid;
        }
        cout << leftt << " " << mid << " " << rightt << endl;
    }
    leftt1 = leftt;
    cout << findcharge(15);
    while(leftt1 < rightt1){
        mid = (leftt1 + rightt1)/2;
        (findcharge(mid) == T) ? leftt1 = mid + 1 : rightt1 = mid ;
        cout << leftt1 << " " << mid << " " << rightt1 << endl;
    }
    //  cout << leftt <<" " << leftt1 << endl;
    cout << leftt1 - leftt;
}