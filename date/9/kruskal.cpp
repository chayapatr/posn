#include <iostream>
#include <vector>
using namespace std;
int parent[10000];
int root(int u){
    if(parent[u] == u) return u;
    return parent[u] = root(parent[u]);
}
void merge(int u, int v){
    u = root(u), v = root(v);
    if(u == v) return;
    parent[u] = v;
}
int main(){
    vector<pair<int, pair<int, int> > > e;
    e.push_back({10,{0,2}});
    e.push_back({2,{0,3}});
    e.push_back({3,{3,2}});
    e.push_back({5,{0,1}});
    e.push_back({10,{1,4}});
    for(int i=0;i<100;i++) parent[i]=i;
    sort(e.begin(),e.end());
    int sum = 0;
    for(auto el : e) {
        int u = el.second.first;
        int v = el.second.second;
        int ru = root(u);
        int rv = root(v);
        if(root(u) == root(v)) continue;
        sum+=el.first;
        cout << u << " " << v << endl;
        merge(u, v);
    }
    cout << sum;
}