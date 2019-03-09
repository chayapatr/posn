#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n, q;
    vector<int> drink;
    vector<int> sol;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        int in; cin >> in;
        drink.push_back(in);
    }
    for(int c=0;c<q;c++){
        int count = 0, l, r, k;
        vector<int> copy = drink;
        cin >> l >> r >> k;
        sort(&copy[l-1],&copy[r]);
        for(int i=l-1;copy[i]<=k/2;i++)
        for(int j=i+1;j<r;j++) if(copy[i]+copy[j]==k) count++;
        sol.push_back(count);
    }
    for(int i : sol) cout << i << endl;
}