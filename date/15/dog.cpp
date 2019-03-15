#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int dog[1005][1005];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);
    int n,m;
    memset(dog, -100, sizeof(dog));
    cin >> n >> m;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j){
        int input; cin >> input;
        (input==0) ? dog[i][j] = -1 : dog[i][j] = input;
    }
    // for(int i=0;i<n;++i) { for(int j=0;j<m;++j) cout << dog[i][j] << " "; cout << endl;}
    while(true){
        bool spread = false;
        int count = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;++i) for(int j=0;j<m;++j){
            if(dog[i][j]>0) --dog[i][j];
            else if(dog[i][j]==-1) { q.push({i, j}); continue;};
            ++count;
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(dog[i+1][j]>0) {dog[i+1][j] = -1;spread=true;}
            if(dog[i][j+1]>0) {dog[i][j+1] = -1;spread=true;}
            if(i>0) if(dog[i-1][j]>0) {dog[i-1][j] = -1;spread=true;}
            if(j>0) if(dog[i][j-1]>0) {dog[i][j-1] = -1;spread=true;}
        // cout << q.front().first << " " << q.front().second << endl;
        }
        if(!spread) {
            cout << count;
            break;
        }
    }
}