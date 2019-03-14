#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, s[100005], parent[100005];
int root(int u){
    if (parent[u] == u) return u;
    return parent[u] = root(parent[u]);
}
void merge(int u, int v){
    u = root(u); v = root(v);
    if(u == v) return;
    parent[u] = v;
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);
    vector<pair<int, pair<int, int>>> edgeList;
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        cin >> s[i];
    }
    cin >> n;
    for(int i = 0 ; i < n ; ++i ){
        int from, to;
        cin >> from >> to;
        edgeList.push_back({s[from-1]+s[to-1],{from, to}});
    }
    for(int i = 0 ; i < 100005 ; ++i) parent[i] = i;
    sort(edgeList.begin(), edgeList.end());
    int sum = 0;
    for(auto el : edgeList){
        int u = el.second.first;
        int v = el.second.second;
        int ru = root(u); int rv = root(v);
        if(ru == rv) continue;
        sum += el.first;
        merge(u, v);
    }
    cout << sum;
}