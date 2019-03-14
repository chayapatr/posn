#include<iostream>
#include<vector>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > a[100000];
int b[100000] = {0};
int main(){
    int n, m, ans;
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        int input; cin >> input;
        a[i].push(input);
    }
    for(int j=0;j<m;j++){
        int index=0,maxnum=0;
        for(int i=0;i<n;i++){
            if(a[i].top() > maxnum) {
                index = i; maxnum = a[i].top();
            }
            a[i].pop();
        }
        b[index]++;
    }
    for(int i=0;i<n;i++) if(b[i]>b[ans]) ans = i;
    cout << ++ans;
}